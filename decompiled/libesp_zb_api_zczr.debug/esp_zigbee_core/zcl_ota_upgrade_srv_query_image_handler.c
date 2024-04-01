/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> zcl_ota_upgrade_srv_query_image_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_ota_upgrade_srv_query_image_handler(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
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
    bVar4 = 0xff;
  }
  else {
    bVar4 = *(byte *)(iVar2 + 4);
  }
  _uStack_2c = CONCAT22(0x19,(ushort)bVar4);
  iStack_20 = (uint)*(ushort *)(iVar2 + 0x2b) << 0x10;
  uStack_1c = (uint)*(ushort *)(iVar2 + 0x2d);
  uStack_18 = *(undefined4 *)(iVar2 + 0x2f);
  uStack_14 = *(undefined4 *)(iVar2 + 0x33);
  puVar1 = *(undefined4 **)(iVar2 + 0x27);
  uStack_28 = *puVar1;
  uStack_24 = puVar1[1];
  iStack_20 = CONCAT31(iStack_20._1_3_,*(undefined1 *)(puVar1 + 2));
  if (zb_core_action_cb == (code *)0x0) {
    uVar3 = 0;
  }
  else {
    (*zb_core_action_cb)(6,&local_30);
    uVar3 = esp_err_to_zb_ret();
  }
  return uVar3;
}

