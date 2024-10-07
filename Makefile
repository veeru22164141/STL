.PHONY: clean All

All:
	@echo "----------Building project:[ stdArraySTL - Debug ]----------"
	@cd "stdArraySTL" && "$(MAKE)" -f  "stdArraySTL.mk"
clean:
	@echo "----------Cleaning project:[ stdArraySTL - Debug ]----------"
	@cd "stdArraySTL" && "$(MAKE)" -f  "stdArraySTL.mk" clean
