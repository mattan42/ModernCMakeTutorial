.PHONY: debug
debug:
	cmake -Bbuild/debug . -DCMAKE_BUILD_TYPE=DEBUG && make -C build

.PHONY: release
release:
	cmake -Bbuild/release . -DCMAKE_BUILD_TYPE=RELEASE && make -C build

.PHONY: warning
warning:
	cmake -Bbuild/warning . -DCMAKE_BUILD_TYPE=WARNING && make -C build
