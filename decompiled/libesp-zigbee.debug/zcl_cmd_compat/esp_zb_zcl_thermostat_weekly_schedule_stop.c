/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_zcl_thermostat_weekly_schedule_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zb_zcl_thermostat_weekly_schedule_stop(void)

{
  uint8_t uVar1;
  undefined3 extraout_var;
  esp_err_t eVar2;
  
  uVar1 = get_endpoint_by_cluster(0x201,'\x01');
  if (CONCAT31(extraout_var,uVar1) == 0) {
    eVar2 = 0x105;
  }
  else {
    ezb_zcl_thermostat_weekly_schedule_loop_stop();
    eVar2 = 0;
  }
  return eVar2;
}

