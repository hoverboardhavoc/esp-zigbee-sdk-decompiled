/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_zcl_thermostat_weekly_schedule_get_next_record
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zb_zcl_thermostat_weekly_schedule_get_next_record
                    (uint16_t *iterator,esp_zb_zcl_thermostat_weekly_schedule_record_t *record)

{
  byte bVar1;
  uint uVar2;
  uint8_t uVar3;
  undefined3 extraout_var;
  uint8_t *puVar4;
  esp_err_t eVar5;
  int iVar6;
  
  if (iterator == (uint16_t *)0x0) {
    eVar5 = 0x102;
  }
  else if (record == (esp_zb_zcl_thermostat_weekly_schedule_record_t *)0x0) {
    eVar5 = 0x102;
  }
  else {
    uVar3 = get_endpoint_by_cluster(0x201,'\x01');
    if (CONCAT31(extraout_var,uVar3) == 0) {
      eVar5 = 0x105;
    }
    else {
      uVar2 = (uint)*iterator;
      for (bVar1 = 0; bVar1 < 7; bVar1 = bVar1 + 1) {
        puVar4 = (uint8_t *)
                 ezb_zcl_thermostat_get_weekly_schedule_entry(CONCAT31(extraout_var,uVar3),bVar1);
        if (puVar4 != (uint8_t *)0x0) {
          if (uVar2 < puVar4[1]) {
            record->day_of_week = bVar1;
            record->mode_for_seq = *puVar4;
            iVar6 = uVar2 * 6;
            record->transition_time = *(uint16_t *)(*(int *)(puVar4 + 4) + iVar6);
            record->heat_setpoint = *(uint16_t *)(*(int *)(puVar4 + 4) + iVar6 + 2);
            record->cool_setpoint = *(uint16_t *)(iVar6 + *(int *)(puVar4 + 4) + 4);
            *iterator = *iterator + 1;
            return 0;
          }
          uVar2 = uVar2 - puVar4[1] & 0xffff;
        }
      }
      *iterator = 0xffff;
      eVar5 = 0x105;
    }
  }
  return eVar5;
}

