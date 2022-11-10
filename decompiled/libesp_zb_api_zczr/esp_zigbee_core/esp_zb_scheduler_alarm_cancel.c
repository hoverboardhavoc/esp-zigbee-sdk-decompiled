/*
 * Last changed at upstream commit 6f86421a4970072ce8039b9d5be911c385f38303
 * https://github.com/espressif/esp-zigbee-sdk/commit/6f86421a4970072ce8039b9d5be911c385f38303
 * Upstream date: 2022-11-10 11:13:02 +0800
 * Upstream subject: examples: apply new signal handler API function
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_scheduler_alarm_cancel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_scheduler_alarm_cancel(void)

{
  zb_schedule_alarm_cancel(0);
  return;
}

