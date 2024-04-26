/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_reset_startup_parameters
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
  DAT_00011782 = 0xff;
  DAT_00011783 = 0xff;
  DAT_00011784 = 0xff;
  DAT_00011785 = 0xff;
  DAT_00011786 = 0xff;
  DAT_00011787 = 0xff;
  DAT_00011788 = 0xff;
  DAT_00011789 = 0xff;
  DAT_0001178a = uVar2;
  DAT_0001178c = uVar3;
  DAT_00011790 = 2;
  DAT_00011791 = 2;
  DAT_00011792 = 3;
  DAT_000117bb = 1;
  DAT_000117cd = 1;
  return;
}

