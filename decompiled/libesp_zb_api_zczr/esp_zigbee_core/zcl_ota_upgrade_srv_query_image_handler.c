/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_ota_upgrade_srv_query_image_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_ota_upgrade_srv_query_image_handler(void)

{
  int iVar1;
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
  uStack_28 = 0;
  uStack_24 = 0;
  bVar3 = 0xff;
  if (iVar2 != 0) {
    bVar3 = *(byte *)(iVar2 + 4);
  }
  _uStack_2c = CONCAT22(0x19,(ushort)bVar3);
  iStack_20 = (uint)*(ushort *)(iVar2 + 0x2b) << 0x10;
  uStack_1c = (uint)*(ushort *)(iVar2 + 0x2d);
  uStack_18 = *(undefined4 *)(iVar2 + 0x2f);
  uStack_14 = *(undefined4 *)(iVar2 + 0x33);
  memcpy(&uStack_28,*(void **)(iVar2 + 0x27),9);
  if (zb_core_action_cb == (code *)0x0) {
    return 0;
  }
  iVar2 = (*zb_core_action_cb)(6,&local_30);
  if (iVar2 == 0x105) {
    iVar1 = -0x1c;
  }
  else if (iVar2 < 0x106) {
    iVar1 = -0x16;
    if ((iVar2 != 0x101) && (iVar1 = -6, iVar2 != 0x104)) {
      return -(uint)(iVar2 != 0);
    }
  }
  else {
    iVar1 = -0x1e;
    if ((iVar2 != 0x107) && (iVar1 = -2, iVar2 != 0x10c)) {
      return -1;
    }
  }
  return iVar1;
}

