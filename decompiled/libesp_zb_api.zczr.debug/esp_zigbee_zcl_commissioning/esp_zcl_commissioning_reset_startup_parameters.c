/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_reset_startup_parameters
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zcl_commissioning_reset_startup_parameters(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  
  uVar1 = esp_zb_get_short_address();
  uVar2 = esp_zb_get_pan_id();
  uVar3 = zb_get_channel_mask();
  memset(&g_comm_ctx,0,0x50);
  g_comm_ctx = uVar1;
  DAT_0001179a = 0xff;
  DAT_0001179b = 0xff;
  DAT_0001179c = 0xff;
  DAT_0001179d = 0xff;
  DAT_0001179e = 0xff;
  DAT_0001179f = 0xff;
  DAT_000117a0 = 0xff;
  DAT_000117a1 = 0xff;
  DAT_000117a2 = uVar2;
  DAT_000117a4 = uVar3;
  DAT_000117a8 = 2;
  DAT_000117a9 = 2;
  DAT_000117aa = 3;
  DAT_000117d3 = 1;
  DAT_000117e5 = 1;
  return;
}

