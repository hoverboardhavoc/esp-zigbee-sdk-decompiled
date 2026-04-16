/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> power_config.o -> power_config_cluster_srv_write_attr_hook
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void power_config_cluster_srv_write_attr_hook
               (uint8_t endpoint,uint16_t attr_id,void *new_value,uint16_t manuf_code)

{
  undefined2 in_register_0000202e;
  int iVar1;
  
  iVar1 = CONCAT22(in_register_0000202e,attr_id);
  if (iVar1 == 0) {
    power_config_check_mains_voltage(endpoint,new_value);
  }
  else if (((iVar1 == 0x20) || (iVar1 == 0x40)) || (iVar1 == 0x60)) {
    power_config_check_battery_value(endpoint,new_value,attr_id);
  }
  else if (((iVar1 == 0x21) || (iVar1 == 0x41)) || (iVar1 == 0x61)) {
    power_config_check_battery_percentage_value(endpoint,attr_id,new_value);
  }
  return;
}

