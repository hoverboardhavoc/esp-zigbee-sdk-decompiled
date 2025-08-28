/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_alarms.o -> esp_zb_zcl_alarms_init_client
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zcl_alarms_init_client(void)

{
  zb_zcl_alarms_init_client();
  zb_zcl_device_cb_register(0x69,zcl_alarms_alarm_handler);
  zb_zcl_endpoint_handler_register(9,zb_zcl_alarms_req_resp_handler);
  return;
}

