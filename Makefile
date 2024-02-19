CC = gcc
FLAGS = -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast

test_objects:
	@if [ $$(cat lib/objects/objects.c | wc -l) -le 10 ]; then \
		echo "lib/objects/objects.c is empty, skipping test..."; \
	else \
		$(CC) $(FLAGS) test/test_objects.c lib/objects/objects.c -o test/test_objects.out && ./test/test_objects.out; \
	fi

test_list:
	@if [ $$(cat lib/list/list.c | wc -l) -le 10 ]; then \
		echo "lib/list/list.c is empty, skipping test..."; \
	else \
		$(CC) $(FLAGS) test/test_list.c lib/list/list.c -o test/test_list.out && ./test/test_list.out; \
	fi

test_stack:
	@if [ $$(cat lib/stack/stack.c | wc -l) -le 10 ]; then \
		echo "lib/stack/stack.c is empty, skipping test..."; \
	else \
		$(CC) $(FLAGS) test/test_stack.c lib/stack/stack.c -o test/test_stack.out && ./test/test_stack.out; \
	fi

test_queue:
	@if [ $$(cat lib/queue/queue.c | wc -l) -le 10 ]; then \
		echo "lib/queue/queue.c is empty, skipping test..."; \
	else \
		$(CC) $(FLAGS) test/test_queue.c lib/queue/queue.c -o test/test_queue.out && ./test/test_queue.out; \
	fi

test_tree:
	@if [ $$(cat lib/tree/tree.c | wc -l) -le 10 ]; then \
		echo "lib/tree/tree.c is empty, skipping test..."; \
	else \
		$(CC) $(FLAGS) test/test_tree.c lib/tree/tree.c lib/list/list.c lib/queue/queue.c lib/stack/stack.c -o test/test_tree.out && ./test/test_tree.out; \
	fi

test_graph:
	@if [ $$(cat lib/graph/graph.c | wc -l) -le 10 ]; then \
		echo "lib/graph/graph.c is empty, skipping test..."; \
	else \
		$(CC) $(FLAGS) test/test_graph.c lib/graph/graph.c lib/list/list.c -o test/test_graph.out && ./test/test_graph.out; \
	fi

test_hash:
	@if [ $$(cat lib/hash/hash.c | wc -l) -le 10 ]; then \
		echo "lib/hash/hash.c is empty, skipping test..."; \
	else \
		$(CC) $(FLAGS) test/test_hash.c lib/hash/hash.c lib/list/list.c -o test/test_hash.out -lm && ./test/test_hash.out; \
	fi

test_all: test_objects test_list test_stack test_queue test_tree test_graph test_hash
	echo "All tests passed!"

clean:
	rm -f test/*out*
	rm -rf src/tp*/*out*
	for tp in tp0 tp1 tp2 tp3 tp4 tp5; do rm -f src/$tp/*.out; done
