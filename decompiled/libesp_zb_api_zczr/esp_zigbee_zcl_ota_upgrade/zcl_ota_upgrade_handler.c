/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_ota_upgrade.o -> zcl_ota_upgrade_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_ota_upgrade_handler(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  void *__src;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  uint uStack_40;
  undefined1 auStack_3c [2];
  undefined2 uStack_3a;
  uint uStack_38;
  undefined2 uStack_34;
  undefined2 uStack_32;
  undefined4 uStack_30;
  int iStack_2c;
  ushort uStack_28;
  void *pvStack_24;
  
  iVar2 = zb_buf_get_tail_func(0x38);
  memset(auStack_3c,0,0x1c);
  uStack_40 = (uint)(iVar2 == 0);
  auStack_3c[0] = 0xff;
  if (iVar2 != 0) {
    auStack_3c[0] = *(undefined1 *)(iVar2 + 4);
  }
  uStack_3a = 0x19;
  uStack_38 = (uint)*(byte *)(iVar2 + 0xc);
  iVar3 = esp_zb_has_core_action_handler();
  if (iVar3 != 0) {
    if (*(char *)(iVar2 + 0xc) == '\x02') {
      bVar1 = *(byte *)(iVar2 + 0x14);
      uVar5 = *(uint *)(iVar2 + 0x10);
      __src = *(void **)(iVar2 + 0x18);
      uVar6 = bVar1 + uVar5;
      if (uVar6 < 0x39) {
        memcpy(ota_header_0,__src,(uint)bVar1);
      }
      else if (uVar5 < 0x38) {
        memcpy(ota_header_0 + uVar5,__src,0x38 - uVar5);
        uStack_28 = (short)uVar6 - 0x38;
        pvStack_24 = (void *)((int)__src + (0x38 - uVar5));
      }
      else {
        uStack_28 = (ushort)bVar1;
        pvStack_24 = __src;
      }
    }
    uStack_34 = ota_header_0._10_2_;
    uStack_32 = ota_header_0._12_2_;
    uStack_30 = ota_header_0._14_4_;
    iStack_2c = ota_header_0._52_4_ + -0x38;
    if ((((*(char *)(iVar2 + 0xc) == '\x02') && (pvStack_24 == (void *)0x0)) && (uStack_28 == 0)) ||
       (iVar3 = esp_zb_core_action_handler_schedule(4,&uStack_40), iVar3 == 0)) {
      *(undefined1 *)(iVar2 + 0xc) = 6;
      return 0;
    }
    if (iVar3 == 0x105) {
      uVar4 = 10;
    }
    else if (iVar3 == 0x10c) {
      uVar4 = 9;
    }
    else {
      uVar4 = 7;
    }
    *(undefined1 *)(iVar2 + 0xc) = uVar4;
  }
  return 0xffffffff;
}

