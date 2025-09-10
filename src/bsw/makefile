# Build Basic Software Layer
.PHONY: all

MCAL_PATH = mcal
HAL_PATH  = hal
CDD_PATH  = cdd
SERV_PATH = services
RTE_PATH  = rte

all:
	@echo "Building Basic Software...!"
	@$(MAKE) -C $(MCAL_PATH)
	@$(MAKE) -C $(HAL_PATH)
	@$(MAKE) -C $(CDD_PATH)
	@$(MAKE) -C $(SERV_PATH)
	@$(MAKE) -C $(RTE_PATH)