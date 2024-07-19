/*
 * Last changed at upstream commit 280ac146dc8285567eab4df113b3f6356493fe0b
 * https://github.com/espressif/esp-zigbee-sdk/commit/280ac146dc8285567eab4df113b3f6356493fe0b
 * Upstream date: 2024-07-19 11:49:15 +0800
 * Upstream subject: esp-zigbee-lib:(94bd7a1a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_ota_upgrade.o -> zcl_ota_upgrade_query_image_resp_handler
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
  int iStack_20;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  local_30 = (uint)(iVar1 == 0);
  uStack_28 = 0;
  uStack_24 = 0;
  bVar2 = 0xff;
  if (iVar1 != 0) {
    bVar2 = *(byte *)(iVar1 + 4);
  }
  _uStack_2c = CONCAT22(0x19,(ushort)bVar2);
  iStack_20 = (uint)CONCAT11(*(undefined1 *)(iVar1 + 0xc),*(undefined1 *)(iVar1 + 0x16)) << 8;
  uStack_1c = *(undefined2 *)(iVar1 + 0x17);
  uStack_1a = *(undefined2 *)(iVar1 + 0x19);
  uStack_18 = *(undefined4 *)(iVar1 + 0x1b);
  uStack_14 = *(undefined4 *)(iVar1 + 0x1f);
  memcpy(&uStack_28,(void *)(iVar1 + 0xd),9);
  esp_zb_core_action_handler_schedule(0x31,&local_30);
  esp_err_to_zb_ret();
  return;
}

