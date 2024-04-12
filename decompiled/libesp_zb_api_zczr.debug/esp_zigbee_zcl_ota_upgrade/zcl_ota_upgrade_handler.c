/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_ota_upgrade.o -> zcl_ota_upgrade_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_ota_upgrade_handler(void)

{
  uint __n;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  uint uVar5;
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
  
  iVar1 = zb_buf_get_tail_func(0x38);
  uStack_34 = 0;
  uStack_30 = 0;
  iStack_2c = 0;
  uStack_28 = 0;
  pvStack_24 = (void *)0x0;
  local_40 = (uint)(iVar1 == 0);
  if (iVar1 == 0) {
    bVar4 = 0xff;
  }
  else {
    bVar4 = *(byte *)(iVar1 + 4);
  }
  _uStack_3c = CONCAT22(0x19,(ushort)bVar4);
  uStack_38 = (uint)*(byte *)(iVar1 + 0xc);
  iVar2 = esp_zb_has_core_action_handler();
  if (iVar2 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_L0,uVar3,0x10000,"zcl_ota_upgrade_handler",0x42);
    return -1;
  }
  if (*(char *)(iVar1 + 0xc) == '\x02') {
    __n = (uint)*(byte *)(iVar1 + 0x14);
    uVar5 = *(uint *)(iVar1 + 0x10);
    __src = *(void **)(iVar1 + 0x18);
    if (__n + uVar5 < 0x39) {
      memcpy(ota_header_0,__src,__n);
    }
    else if (uVar5 < 0x38) {
      memcpy(ota_header_0 + uVar5,__src,0x38 - uVar5);
      uStack_28 = CONCAT22(uStack_28._2_2_,(short)((__n + uVar5) * 0x10000 >> 0x10) + -0x38);
      pvStack_24 = (void *)((0x38 - uVar5) + (int)__src);
    }
    else {
      uStack_28 = CONCAT22(uStack_28._2_2_,(ushort)*(byte *)(iVar1 + 0x14));
      pvStack_24 = __src;
    }
  }
  uStack_34 = CONCAT22(ota_header_0._12_2_,ota_header_0._10_2_);
  uStack_30 = ota_header_0._14_4_;
  iStack_2c = ota_header_0._52_4_ + -0x38;
  if (((*(char *)(iVar1 + 0xc) == '\x02') && (pvStack_24 == (void *)0x0)) &&
     ((uStack_28 & 0xffff) == 0)) {
    *(undefined1 *)(iVar1 + 0xc) = 6;
    iVar2 = 0;
  }
  else {
    iVar2 = esp_zb_core_action_handler_schedule(4,&local_40);
    if (iVar2 == 0) {
      *(undefined1 *)(iVar1 + 0xc) = 6;
      return 0;
    }
    if (iVar2 == 0x105) {
      *(undefined1 *)(iVar1 + 0xc) = 10;
      return -1;
    }
    if (iVar2 == 0x10c) {
      *(undefined1 *)(iVar1 + 0xc) = 9;
      return -1;
    }
    *(undefined1 *)(iVar1 + 0xc) = 7;
  }
  if (iVar2 != 0) {
    iVar2 = -1;
  }
  return iVar2;
}

