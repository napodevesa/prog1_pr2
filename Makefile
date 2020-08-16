.PHONY: clean All

All:
	@echo "----------Building project:[ UOCBookings - Test ]----------"
	@"$(MAKE)" -f  "UOCBookings.mk"
clean:
	@echo "----------Cleaning project:[ UOCBookings - Test ]----------"
	@"$(MAKE)" -f  "UOCBookings.mk" clean
