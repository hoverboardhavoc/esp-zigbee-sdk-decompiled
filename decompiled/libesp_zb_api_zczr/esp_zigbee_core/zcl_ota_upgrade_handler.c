/*
 * Last changed at upstream commit 9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * https://github.com/espressif/esp-zigbee-sdk/commit/9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * Upstream date: 2023-11-10 18:10:39 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.3(ba5a889a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_ota_upgrade_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_ota_upgrade_handler(void)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  uint __n;
  uint uVar6;
  void *__src;
  uint local_40;
  ushort uStack_3c;
  undefined2 uStack_3a;
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  uint uStack_28;
  void *pvStack_24;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  pcVar1 = zb_core_action_cb;
  uStack_34 = 0;
  uStack_30 = 0;
  iStack_2c = 0;
  uStack_28 = 0;
  pvStack_24 = (void *)0x0;
  local_40 = (uint)(iVar2 == 0);
  if (iVar2 == 0) {
    bVar5 = 0xff;
  }
  else {
    bVar5 = *(byte *)(iVar2 + 4);
  }
  _uStack_3c = CONCAT22(0x19,(ushort)bVar5);
  uStack_38 = (uint)*(byte *)(iVar2 + 0xc);
  if (zb_core_action_cb == (code *)0x0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar4,"ESP_ZIGBEE_CORE","zcl_ota_upgrade_handler",0x3e6);
    return -1;
  }
  if (uStack_38 == 2) {
    __n = (uint)*(byte *)(iVar2 + 0x14);
    uVar6 = *(uint *)(iVar2 + 0x10);
    __src = *(void **)(iVar2 + 0x18);
    if (__n + uVar6 < 0x39) {
      memcpy(ota_header_6,__src,__n);
    }
    else if (uVar6 < 0x38) {
      memcpy(ota_header_6 + uVar6,__src,0x38 - uVar6);
      uStack_28 = CONCAT22(uStack_28._2_2_,(short)((__n + uVar6) * 0x10000 >> 0x10) + -0x38);
      pvStack_24 = (void *)((0x38 - uVar6) + (int)__src);
    }
    else {
      uStack_28 = (uint)*(byte *)(iVar2 + 0x14);
      pvStack_24 = __src;
    }
  }
  uStack_34 = CONCAT22(ota_header_6._12_2_,ota_header_6._10_2_);
  uStack_30 = ota_header_6._14_4_;
  iStack_2c = ota_header_6._52_4_ + -0x38;
  if (((*(char *)(iVar2 + 0xc) == '\x02') && (pvStack_24 == (void *)0x0)) &&
     ((uStack_28 & 0xffff) == 0)) {
    *(undefined1 *)(iVar2 + 0xc) = 6;
    iVar3 = 0;
  }
  else {
    iVar3 = (*pcVar1)(4,&local_40);
    if (iVar3 == 0) {
      *(undefined1 *)(iVar2 + 0xc) = 6;
      return 0;
    }
    if (iVar3 == 0x105) {
      *(undefined1 *)(iVar2 + 0xc) = 10;
      return -1;
    }
    if (iVar3 == 0x10c) {
      *(undefined1 *)(iVar2 + 0xc) = 9;
      return -1;
    }
    *(undefined1 *)(iVar2 + 0xc) = 7;
  }
  if (iVar3 != 0) {
    iVar3 = -1;
  }
  return iVar3;
}

