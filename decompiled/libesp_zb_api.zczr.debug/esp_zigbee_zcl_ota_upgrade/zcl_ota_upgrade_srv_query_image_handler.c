/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_ota_upgrade.o -> zcl_ota_upgrade_srv_query_image_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_ota_upgrade_srv_query_image_handler(void)

{
  undefined4 *puVar1;
  int iVar2;
  byte bVar3;
  uint local_30;
  ushort uStack_2c;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  uint uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  local_30 = (uint)(iVar2 == 0);
  if (iVar2 == 0) {
    bVar3 = 0xff;
  }
  else {
    bVar3 = *(byte *)(iVar2 + 4);
  }
  _uStack_2c = CONCAT22(0x19,(ushort)bVar3);
  iStack_20 = (uint)*(ushort *)(iVar2 + 0x2b) << 0x10;
  uStack_1c = (uint)*(ushort *)(iVar2 + 0x2d);
  uStack_18 = *(undefined4 *)(iVar2 + 0x2f);
  uStack_14 = *(undefined4 *)(iVar2 + 0x33);
  puVar1 = *(undefined4 **)(iVar2 + 0x27);
  uStack_28 = *puVar1;
  uStack_24 = puVar1[1];
  iStack_20 = CONCAT31(iStack_20._1_3_,*(undefined1 *)(puVar1 + 2));
  esp_zb_core_action_handler_schedule(6,&local_30);
  esp_err_to_zb_ret();
  return;
}

