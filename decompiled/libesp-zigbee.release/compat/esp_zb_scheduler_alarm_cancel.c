/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> compat.o -> esp_zb_scheduler_alarm_cancel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_scheduler_alarm_cancel(esp_zb_callback_t cb,uint8_t param)

{
  int iVar1;
  esp_zb_alarm_t *alarm;
  undefined3 in_register_0000202d;
  esp_zb_alarm_t **ppeVar2;
  
  ppeVar2 = s_alarms;
  iVar1 = 0;
  while (((alarm = *ppeVar2, alarm == (esp_zb_alarm_t *)0x0 || ((alarm->params).field_0.cb != cb))
         || ((uint)(alarm->params).field_1.param != CONCAT31(in_register_0000202d,param)))) {
    iVar1 = iVar1 + 1;
    ppeVar2 = ppeVar2 + 1;
    if (iVar1 == 8) {
      return;
    }
  }
  esp_zb_cancel_alarm(alarm);
  s_alarms[iVar1] = (esp_zb_alarm_t *)0x0;
  return;
}

