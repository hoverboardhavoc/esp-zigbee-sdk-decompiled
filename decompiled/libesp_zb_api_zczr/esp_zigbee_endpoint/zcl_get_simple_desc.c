/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_endpoint.o -> zcl_get_simple_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 *
zcl_get_simple_desc(undefined2 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  undefined2 uVar3;
  byte bVar4;
  void *__ptr;
  undefined1 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined1 uStack_28;
  undefined1 uStack_25;
  undefined1 uStack_24;
  
  bVar1 = *(byte *)(param_2 + 2);
  uVar7 = (uint)bVar1;
  bVar2 = *(byte *)(param_2 + 3);
  __ptr = malloc(0xc);
  puVar5 = (undefined1 *)realloc(__ptr,(uVar7 + bVar2 + 4) * 2);
  uStack_28 = (undefined1)param_3;
  *puVar5 = uStack_28;
  puVar5[1] = (char)((uint)param_3 >> 8);
  puVar5[2] = (char)((uint)param_3 >> 0x10);
  uStack_25 = (undefined1)((uint)param_3 >> 0x18);
  uStack_24 = (undefined1)param_4;
  puVar5[3] = uStack_25;
  puVar5[4] = uStack_24;
  bVar4 = (byte)((uint)param_4 >> 8) & 0xf;
  puVar5[5] = puVar5[5] & 0xf0 | bVar4;
  puVar5[5] = bVar4;
  puVar5[6] = bVar1;
  puVar5[7] = bVar2;
  if (param_1 == (undefined2 *)0x0) {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar6,0x10000);
  }
  uVar8 = 0;
  while (param_1 = *(undefined2 **)(param_1 + 8), param_1 != (undefined2 *)0x0) {
    if (*(char *)(param_1 + 4) == '\x01') {
      uVar3 = *param_1;
      puVar5[uVar8 * 2 + 8] = (char)uVar3;
      puVar5[uVar8 * 2 + 9] = (char)((ushort)uVar3 >> 8);
      uVar8 = uVar8 + 1 & 0xff;
    }
    else if (*(char *)(param_1 + 4) == '\x02') {
      uVar3 = *param_1;
      puVar5[uVar7 * 2 + 8] = (char)uVar3;
      puVar5[uVar7 * 2 + 9] = (char)((ushort)uVar3 >> 8);
      uVar7 = uVar7 + 1 & 0xff;
    }
    else {
      uVar6 = esp_log_timestamp();
      esp_log_write(2,0x10000,&_L0,uVar6,0x10000,*(undefined1 *)(param_1 + 4));
    }
  }
  return puVar5;
}

