/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_ota_upgrade.o -> zcl_ota_upgrade_query_image_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_ota_upgrade_query_image_resp_handler(void)

{
  int iVar1;
  byte bVar2;
  uint local_30;
  ushort uStack_2c;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  local_30 = (uint)(iVar1 == 0);
  if (iVar1 == 0) {
    bVar2 = 0xff;
  }
  else {
    bVar2 = *(byte *)(iVar1 + 4);
  }
  _uStack_2c = CONCAT22(0x19,(ushort)bVar2);
  uStack_1c = *(undefined4 *)(iVar1 + 0x17);
  uStack_18 = *(undefined4 *)(iVar1 + 0x1b);
  uStack_14 = *(undefined4 *)(iVar1 + 0x1f);
  uStack_28 = *(undefined4 *)(iVar1 + 0xd);
  uStack_24 = *(undefined4 *)(iVar1 + 0x11);
  uStack_20 = (uint)CONCAT21(CONCAT11(*(undefined1 *)(iVar1 + 0xc),*(undefined1 *)(iVar1 + 0x16)),
                             *(undefined1 *)(iVar1 + 0x15));
  esp_zb_core_action_handler_schedule(0x31,&local_30);
  esp_err_to_zb_ret();
  return;
}

