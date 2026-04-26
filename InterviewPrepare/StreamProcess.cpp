#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <unordered_map>
#include <span>
#include <cstdint>

struct Task {
    uint64_t task_id;
    size_t offset;
    size_t length;
};

class StreamProcessor {
private:
    // TODO 1: Объяви фиксированный массив для 9 весов фильтра
    std::array<float, 9> weights_;

    // TODO 2: Объяви очередь задач (с учетом требований к добавлению в конец и взятию с начала)
    std::deque<Task> task_queue_;

    // TODO 3: Объяви хэш-таблицу для кэша (task_id -> float). 
    std::unordered_map<uint64_t, float>  cache_;

    // TODO 4: Объяви динамический массив для результатов (float).
    std::vector<float> results_; // Предполагаем максимум 10 000 результатов, инициализируем нулями.

    // TODO 5: Объяви маску превышения порога (true/false) для каждого результата.
    // Помни про ловушку с битовыми полями! Выбери безопасный для многопоточности/железа тип.
    std::vector<uint8_t> threshold_mask_;

public:
    StreamProcessor() {
        // TODO 6: Сделай предварительные аллокации (reserve), 
        // чтобы избежать реаллокаций для 10 000 результатов 
        // и избежать внезапного рехэша кэша (допустим, ожидаем 5000 уникальных тасок).

        results_.reserve(10000);
        threshold_mask_.reserve(10000);
        cache_.reserve(5000);
    }

    void enqueue_task(uint64_t id, size_t offset, size_t length) {
        // TODO 7: Положи задачу в очередь.
        task_queue_.emplace_back(id, offset, length);
    }

    // TODO 8: Измени сигнатуру функции так, чтобы она принимала сырой буфер 
    // БЕЗ копирования и потери информации о размере (используй C++20).
    void process_batch(/* const float* raw_data, size_t size */ std::span<const float> raw_data) {
        
        while (!task_queue_.empty()) {
            // TODO 9: Достань задачу из очереди (и удали её оттуда)
            Task current_task = task_queue_.front();
            task_queue_.pop_front();
            
            // TODO 10: Сделай срез (subspan) от входного буфера, используя offset и length таски.
            // Никакого копирования, только просмотр!
            auto chunk = raw_data.subspan(current_task.offset, current_task.length);

            // --- Саму математику свертки писать не нужно ---
            // Представим, что мы посчитали результат:
            float fake_result = 42.0f; 
            bool passed_threshold = true;

            // TODO 11: Сохрани результат в буфер, маску и добавь в кэш
            results_.push_back(fake_result);
            threshold_mask_.push_back(passed_threshold ? 1 : 0);
            cache_.insert_or_assign(current_task.task_id, fake_result);
        }
    }
};