/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
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
  DAT_0001171a = 0xff;
  DAT_0001171b = 0xff;
  DAT_0001171c = 0xff;
  DAT_0001171d = 0xff;
  DAT_0001171e = 0xff;
  DAT_0001171f = 0xff;
  DAT_00011720 = 0xff;
  DAT_00011721 = 0xff;
  DAT_00011722 = uVar2;
  DAT_00011724 = uVar3;
  DAT_00011728 = 2;
  DAT_00011729 = 2;
  DAT_0001172a = 3;
  DAT_00011753 = 1;
  DAT_00011765 = 1;
  return;
}

