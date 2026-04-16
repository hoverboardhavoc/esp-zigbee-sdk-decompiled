/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_thermostat_weekly_schedule_get_next_record
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zb_zcl_thermostat_weekly_schedule_get_next_record
                    (uint16_t *iterator,esp_zb_zcl_thermostat_weekly_schedule_record_t *record)

{
  uint16_t uVar1;
  uint uVar2;
  uint8_t uVar3;
  esp_err_t eVar4;
  undefined3 extraout_var;
  uint8_t *puVar5;
  uint16_t *puVar6;
  uint8_t uVar7;
  
  if (iterator == (uint16_t *)0x0) {
    return 0x102;
  }
  eVar4 = 0x102;
  if (record != (esp_zb_zcl_thermostat_weekly_schedule_record_t *)0x0) {
    uVar3 = get_endpoint_by_cluster(0x102,(uint8_t)record);
    if (CONCAT31(extraout_var,uVar3) != 0) {
      uVar2 = (uint)*iterator;
      uVar7 = '\0';
      do {
        puVar5 = (uint8_t *)
                 ezb_zcl_thermostat_get_weekly_schedule_entry(CONCAT31(extraout_var,uVar3),uVar7);
        if (puVar5 != (uint8_t *)0x0) {
          if (uVar2 < puVar5[1]) {
            record->day_of_week = uVar7;
            record->mode_for_seq = *puVar5;
            puVar6 = (uint16_t *)(*(int *)(puVar5 + 4) + uVar2 * 6);
            record->transition_time = *puVar6;
            uVar1 = puVar6[2];
            record->heat_setpoint = puVar6[1];
            record->cool_setpoint = uVar1;
            *iterator = *iterator + 1;
            return 0;
          }
          uVar2 = uVar2 - puVar5[1] & 0xffff;
        }
        uVar7 = uVar7 + '\x01';
      } while (uVar7 != '\a');
      *iterator = 0xffff;
    }
    eVar4 = 0x105;
  }
  return eVar4;
}

