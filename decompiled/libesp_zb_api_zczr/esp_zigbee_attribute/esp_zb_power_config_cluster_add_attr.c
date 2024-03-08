/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_power_config_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_power_config_cluster_add_attr(int param_1,uint param_2,char *param_3)

{
  undefined2 *__ptr;
  int iVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  size_t sVar4;
  char *pcVar5;
  undefined4 uVar6;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar1 = esp_zb_attr_list_get_tail(param_1,1,param_2,aiStack_24);
  if (aiStack_24[0] != 0) {
    free(__ptr);
    return aiStack_24[0];
  }
  *__ptr = (short)param_2;
  if (param_2 == 0x33) {
    *(undefined1 *)((int)__ptr + 3) = 3;
    *(undefined1 *)(__ptr + 1) = 0x20;
    pcVar5 = (char *)malloc(1);
    *pcVar5 = *param_3;
    __ptr[3] = (short)pcVar5;
    __ptr[4] = (short)((uint)pcVar5 >> 0x10);
  }
  else if (param_2 < 0x34) {
    if (param_2 == 0x13) {
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x21;
      puVar3 = (undefined2 *)malloc(2);
      *puVar3 = *(undefined2 *)param_3;
      __ptr[3] = (short)puVar3;
      __ptr[4] = (short)((uint)puVar3 >> 0x10);
    }
    else if (param_2 < 0x14) {
      if (param_2 == 0x10) {
        *(undefined1 *)((int)__ptr + 3) = 3;
        *(undefined1 *)(__ptr + 1) = 0x18;
        pcVar5 = (char *)malloc(1);
        *pcVar5 = *param_3;
        __ptr[3] = (short)pcVar5;
        __ptr[4] = (short)((uint)pcVar5 >> 0x10);
      }
      else if (param_2 < 0x11) {
        if (param_2 == 0) {
          *(undefined1 *)((int)__ptr + 3) = 1;
          *(undefined1 *)(__ptr + 1) = 0x21;
          puVar3 = (undefined2 *)malloc(2);
          *puVar3 = *(undefined2 *)param_3;
          __ptr[3] = (short)puVar3;
          __ptr[4] = (short)((uint)puVar3 >> 0x10);
        }
        else {
          if (param_2 != 1) goto _L0;
          *(undefined1 *)((int)__ptr + 3) = 1;
          *(undefined1 *)(__ptr + 1) = 0x20;
          pcVar5 = (char *)malloc(1);
          *pcVar5 = *param_3;
          __ptr[3] = (short)pcVar5;
          __ptr[4] = (short)((uint)pcVar5 >> 0x10);
        }
      }
      else if (param_2 == 0x11) {
        *(undefined1 *)((int)__ptr + 3) = 3;
        *(undefined1 *)(__ptr + 1) = 0x21;
        puVar3 = (undefined2 *)malloc(2);
        *puVar3 = *(undefined2 *)param_3;
        __ptr[3] = (short)puVar3;
        __ptr[4] = (short)((uint)puVar3 >> 0x10);
      }
      else {
        if (param_2 != 0x12) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 3;
        *(undefined1 *)(__ptr + 1) = 0x21;
        puVar3 = (undefined2 *)malloc(2);
        *puVar3 = *(undefined2 *)param_3;
        __ptr[3] = (short)puVar3;
        __ptr[4] = (short)((uint)puVar3 >> 0x10);
      }
    }
    else if (param_2 == 0x30) {
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x42;
      sVar4 = strlen(param_3);
      pcVar5 = (char *)malloc(sVar4 + 1);
      strcpy(pcVar5,param_3);
      __ptr[3] = (short)pcVar5;
      __ptr[4] = (short)((uint)pcVar5 >> 0x10);
    }
    else if (param_2 < 0x31) {
      if (param_2 == 0x20) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x20;
        pcVar5 = (char *)malloc(1);
        *pcVar5 = *param_3;
        __ptr[3] = (short)pcVar5;
        __ptr[4] = (short)((uint)pcVar5 >> 0x10);
      }
      else {
        if (param_2 != 0x21) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 5;
        *(undefined1 *)(__ptr + 1) = 0x20;
        pcVar5 = (char *)malloc(1);
        *pcVar5 = *param_3;
        __ptr[3] = (short)pcVar5;
        __ptr[4] = (short)((uint)pcVar5 >> 0x10);
      }
    }
    else if (param_2 == 0x31) {
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x30;
      pcVar5 = (char *)malloc(1);
      *pcVar5 = *param_3;
      __ptr[3] = (short)pcVar5;
      __ptr[4] = (short)((uint)pcVar5 >> 0x10);
    }
    else {
      if (param_2 != 0x32) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x21;
      puVar3 = (undefined2 *)malloc(2);
      *puVar3 = *(undefined2 *)param_3;
      __ptr[3] = (short)puVar3;
      __ptr[4] = (short)((uint)puVar3 >> 0x10);
    }
  }
  else if (param_2 == 0x39) {
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x20;
    pcVar5 = (char *)malloc(1);
    *pcVar5 = *param_3;
    __ptr[3] = (short)pcVar5;
    __ptr[4] = (short)((uint)pcVar5 >> 0x10);
  }
  else if (param_2 < 0x3a) {
    if (param_2 == 0x36) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x20;
      pcVar5 = (char *)malloc(1);
      *pcVar5 = *param_3;
      __ptr[3] = (short)pcVar5;
      __ptr[4] = (short)((uint)pcVar5 >> 0x10);
    }
    else if (param_2 < 0x37) {
      if (param_2 == 0x34) {
        *(undefined1 *)((int)__ptr + 3) = 3;
        *(undefined1 *)(__ptr + 1) = 0x20;
        pcVar5 = (char *)malloc(1);
        *pcVar5 = *param_3;
        __ptr[3] = (short)pcVar5;
        __ptr[4] = (short)((uint)pcVar5 >> 0x10);
      }
      else {
        if (param_2 != 0x35) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 3;
        *(undefined1 *)(__ptr + 1) = 0x18;
        pcVar5 = (char *)malloc(1);
        *pcVar5 = *param_3;
        __ptr[3] = (short)pcVar5;
        __ptr[4] = (short)((uint)pcVar5 >> 0x10);
      }
    }
    else if (param_2 == 0x37) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x20;
      pcVar5 = (char *)malloc(1);
      *pcVar5 = *param_3;
      __ptr[3] = (short)pcVar5;
      __ptr[4] = (short)((uint)pcVar5 >> 0x10);
    }
    else {
      if (param_2 != 0x38) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x20;
      pcVar5 = (char *)malloc(1);
      *pcVar5 = *param_3;
      __ptr[3] = (short)pcVar5;
      __ptr[4] = (short)((uint)pcVar5 >> 0x10);
    }
  }
  else if (param_2 == 0x3c) {
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x20;
    pcVar5 = (char *)malloc(1);
    *pcVar5 = *param_3;
    __ptr[3] = (short)pcVar5;
    __ptr[4] = (short)((uint)pcVar5 >> 0x10);
  }
  else if (param_2 < 0x3d) {
    if (param_2 == 0x3a) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x20;
      pcVar5 = (char *)malloc(1);
      *pcVar5 = *param_3;
      __ptr[3] = (short)pcVar5;
      __ptr[4] = (short)((uint)pcVar5 >> 0x10);
    }
    else {
      if (param_2 != 0x3b) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x20;
      pcVar5 = (char *)malloc(1);
      *pcVar5 = *param_3;
      __ptr[3] = (short)pcVar5;
      __ptr[4] = (short)((uint)pcVar5 >> 0x10);
    }
  }
  else if (param_2 == 0x3d) {
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x20;
    pcVar5 = (char *)malloc(1);
    *pcVar5 = *param_3;
    __ptr[3] = (short)pcVar5;
    __ptr[4] = (short)((uint)pcVar5 >> 0x10);
  }
  else {
    if (param_2 != 0x3e) {
_L0:
      uVar6 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_L0,uVar6,"ESP_ZIGBEE_ATTRIBUTE");
      free(__ptr);
      return 0x102;
    }
    *(undefined1 *)((int)__ptr + 3) = 5;
    *(undefined1 *)(__ptr + 1) = 0x1b;
    puVar2 = (undefined4 *)malloc(4);
    *puVar2 = *(undefined4 *)param_3;
    __ptr[3] = (short)puVar2;
    __ptr[4] = (short)((uint)puVar2 >> 0x10);
  }
  __ptr[2] = 0xffff;
  __ptr[5] = 1;
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar1 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar1 + 0xc) = __ptr;
  }
  return 0;
}

