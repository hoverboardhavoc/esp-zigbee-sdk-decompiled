/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_api.o -> ezb_zcl_reporting_info_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_reporting_info_update
                    (ezb_zcl_reporting_info_t info,uint16_t min_interval,uint16_t max_interval,
                    ezb_zcl_attr_variable_t *delta)

{
  ezb_err_t eVar1;
  undefined4 uVar2;
  
  *(uint16_t *)((int)info + 0x10) = min_interval;
  *(uint16_t *)((int)info + 0x12) = max_interval;
  uVar2 = *(undefined4 *)(delta->data + 4);
  *(uint32_t *)((int)info + 0x18) = delta->u24;
  *(undefined4 *)((int)info + 0x1c) = uVar2;
  eVar1 = zcl_reporting_info_update();
  return eVar1;
}

