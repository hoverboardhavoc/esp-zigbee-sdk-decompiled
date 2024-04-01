/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_ota_upgrade_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_ota_upgrade_handler(void)

{
  byte bVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  void *__src;
  undefined1 uVar5;
  uint uVar6;
  uint uVar7;
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
  
  iVar3 = zb_buf_get_tail_func(0x38);
  memset(auStack_3c,0,0x1c);
  pcVar2 = zb_core_action_cb;
  uStack_40 = (uint)(iVar3 == 0);
  auStack_3c[0] = 0xff;
  if (iVar3 != 0) {
    auStack_3c[0] = *(undefined1 *)(iVar3 + 4);
  }
  uStack_3a = 0x19;
  uStack_38 = (uint)*(byte *)(iVar3 + 0xc);
  if (zb_core_action_cb != (code *)0x0) {
    if (uStack_38 == 2) {
      bVar1 = *(byte *)(iVar3 + 0x14);
      uVar6 = *(uint *)(iVar3 + 0x10);
      __src = *(void **)(iVar3 + 0x18);
      uVar7 = bVar1 + uVar6;
      if (uVar7 < 0x39) {
        memcpy(ota_header_0,__src,(uint)bVar1);
      }
      else if (uVar6 < 0x38) {
        memcpy(ota_header_0 + uVar6,__src,0x38 - uVar6);
        uStack_28 = (short)uVar7 - 0x38;
        pvStack_24 = (void *)((int)__src + (0x38 - uVar6));
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
    if ((((*(char *)(iVar3 + 0xc) == '\x02') && (pvStack_24 == (void *)0x0)) && (uStack_28 == 0)) ||
       (iVar4 = (*pcVar2)(4,&uStack_40), iVar4 == 0)) {
      *(undefined1 *)(iVar3 + 0xc) = 6;
      return 0;
    }
    if (iVar4 == 0x105) {
      uVar5 = 10;
    }
    else if (iVar4 == 0x10c) {
      uVar5 = 9;
    }
    else {
      uVar5 = 7;
    }
    *(undefined1 *)(iVar3 + 0xc) = uVar5;
  }
  return 0xffffffff;
}

