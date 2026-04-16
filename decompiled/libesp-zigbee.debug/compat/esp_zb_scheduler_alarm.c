/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> compat.o -> esp_zb_scheduler_alarm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_zb_scheduler_alarm(esp_zb_callback_t cb,uint8_t param,uint32_t time)

{
  uint uVar1;
  anon_union_4_2_34b25e97_for_esp_zb_alarm_params_s_0 aStack_1c;
  esp_zb_alarm_params_t params;
  
  uVar1 = 0;
  while( true ) {
    if (7 < uVar1) {
      return;
    }
    if (s_alarms[uVar1] == (esp_zb_alarm_t *)0x0) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  params.field_1.user_param = (void *)0x0;
  params.field_0._1_3_ = 0;
  params.field_0._0_1_ = param;
  aStack_1c.cb = cb;
  esp_zb_run_alarm((esp_zb_alarm_params_t *)&aStack_1c,time,s_alarms + uVar1);
  return;
}

