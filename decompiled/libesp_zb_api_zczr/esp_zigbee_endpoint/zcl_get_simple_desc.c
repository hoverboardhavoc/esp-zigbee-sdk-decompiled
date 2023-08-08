/*
 * Last changed at upstream commit d04ab25a7353bae74042267d24c5fef5f02d0726
 * https://github.com/espressif/esp-zigbee-sdk/commit/d04ab25a7353bae74042267d24c5fef5f02d0726
 * Upstream date: 2023-08-08 16:02:31 +0800
 * Upstream subject: esp-zigbee-sdk: add touchlink example
 * Source: libesp_zb_api_zczr -> esp_zigbee_endpoint.o -> zcl_get_simple_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 *
zcl_get_simple_desc(undefined2 *param_1,int param_2,undefined1 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  byte bVar1;
  byte bVar2;
  undefined2 uVar3;
  void *__ptr;
  undefined1 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  
  bVar1 = *(byte *)(param_2 + 2);
  uVar6 = (uint)bVar1;
  bVar2 = *(byte *)(param_2 + 3);
  __ptr = malloc(0xc);
  puVar4 = (undefined1 *)realloc(__ptr,(uVar6 + bVar2 + 4) * 2);
  *puVar4 = param_3;
  puVar4[1] = (char)param_4;
  puVar4[2] = (char)((uint)param_4 >> 8);
  puVar4[3] = (char)param_5;
  puVar4[4] = (char)((uint)param_5 >> 8);
  puVar4[5] = puVar4[5] & 0xf0;
  puVar4[5] = 0;
  puVar4[6] = bVar1;
  puVar4[7] = bVar2;
  if (param_1 == (undefined2 *)0x0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar5,0x10000);
  }
  uVar7 = 0;
  while (param_1 = *(undefined2 **)(param_1 + 8), param_1 != (undefined2 *)0x0) {
    if (*(char *)(param_1 + 4) == '\x01') {
      uVar3 = *param_1;
      puVar4[uVar7 * 2 + 8] = (char)uVar3;
      puVar4[uVar7 * 2 + 9] = (char)((ushort)uVar3 >> 8);
      uVar7 = uVar7 + 1 & 0xff;
    }
    else if (*(char *)(param_1 + 4) == '\x02') {
      uVar3 = *param_1;
      puVar4[uVar6 * 2 + 8] = (char)uVar3;
      puVar4[uVar6 * 2 + 9] = (char)((ushort)uVar3 >> 8);
      uVar6 = uVar6 + 1 & 0xff;
    }
    else {
      uVar5 = esp_log_timestamp();
      esp_log_write(2,0x10000,&_L0,uVar5,0x10000,*(undefined1 *)(param_1 + 4));
    }
  }
  return puVar4;
}

