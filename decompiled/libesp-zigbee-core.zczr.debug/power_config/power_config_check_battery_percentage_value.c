/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> power_config.o -> power_config_check_battery_percentage_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void power_config_check_battery_percentage_value(uint8_t ep_id,uint16_t attr_id,void *new_value)

{
  undefined2 in_register_0000202e;
  int iVar1;
  uint16_t base_attr_id;
  uint8_t source;
  
  iVar1 = CONCAT22(in_register_0000202e,attr_id);
  if (new_value != (void *)0x0) {
                    /* WARNING: Load size is inaccurate */
    if (iVar1 == 0x21) {
      source = '\x01';
      base_attr_id = 0x20;
    }
    else if (iVar1 == 0x41) {
      source = '\x02';
      base_attr_id = 0x40;
    }
    else {
      if (iVar1 != 0x61) {
        return;
      }
      source = '\x03';
      base_attr_id = 0x60;
    }
    power_config_check_battery_voltage_or_percentage(ep_id,*new_value,base_attr_id,true,source);
  }
  return;
}

