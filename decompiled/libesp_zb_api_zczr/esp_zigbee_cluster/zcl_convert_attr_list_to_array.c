/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_cluster.o -> zcl_convert_attr_list_to_array
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort zcl_convert_attr_list_to_array(int param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  void *__ptr;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  
  if (param_1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CLUSTER",&_L0,uVar3,"ESP_ZIGBEE_CLUSTER");
  }
  else {
    iVar8 = param_1;
    uVar2 = 0;
    do {
      uVar6 = uVar2;
      iVar5 = iVar8;
      iVar8 = *(int *)(iVar5 + 0xc);
      uVar2 = uVar6 + 1;
    } while (*(int *)(iVar5 + 0xc) != 0);
    if (uVar6 != 0) {
      puVar4 = (undefined4 *)malloc(0x10);
      uVar1 = *(undefined2 *)(iVar5 + 10);
      *(undefined2 *)(puVar4 + 2) = 0;
      puVar4[3] = 0;
      *(undefined2 *)((int)puVar4 + 10) = uVar1;
      *puVar4 = 0xffff;
      puVar4[1] = 0xffff;
      *(undefined4 **)(iVar5 + 0xc) = puVar4;
      uVar2 = uVar6 + 1;
      iVar8 = *(int *)(param_1 + 0xc);
      __ptr = calloc((uint)(ushort)(uVar6 + 1),10);
      uVar7 = 0;
      if (__ptr != (void *)0x0) {
        while( true ) {
          if ((uint)uVar2 <= (uVar7 & 0xffff)) {
            return uVar2;
          }
          iVar5 = uVar7 * 10;
          uVar7 = uVar7 + 1;
          iVar5 = esp_zb_internal_zcl_clone_attribute((void *)(iVar5 + (int)__ptr),iVar8);
          if (iVar5 != 0) break;
          iVar8 = *(int *)(iVar8 + 0xc);
        }
      }
      for (iVar8 = 0; iVar8 < (int)(uint)uVar2; iVar8 = iVar8 + 1) {
        free(*(void **)((int)__ptr + iVar8 * 10 + 6));
      }
      free(__ptr);
    }
  }
  return 0;
}

