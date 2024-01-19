/*
 * Last changed at upstream commit 0c62d9f04d6c4a739fd0a010d54749e3cd6ae209
 * https://github.com/espressif/esp-zigbee-sdk/commit/0c62d9f04d6c4a739fd0a010d54749e3cd6ae209
 * Upstream date: 2024-01-19 19:10:32 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.9(b7135493)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_thermostat_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_thermostat_cluster_add_attr(int param_1,uint param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined2 *__ptr;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar4 = esp_zb_attr_list_get_tail(param_1,0x201,param_2,aiStack_24);
  if (aiStack_24[0] != 0) {
    free(__ptr);
    return aiStack_24[0];
  }
  *__ptr = (short)param_2;
  if (param_2 == 0x1c) {
    *(undefined1 *)((int)__ptr + 3) = 0x13;
    *(undefined1 *)(__ptr + 1) = 0x30;
    puVar5 = (undefined1 *)malloc(1);
    __ptr[3] = (short)puVar5;
    __ptr[4] = (short)((uint)puVar5 >> 0x10);
    *puVar5 = *param_3;
    goto _L0;
  }
  if (param_2 < 0x1d) {
    if (param_2 == 0x10) {
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x28;
      puVar5 = (undefined1 *)malloc(1);
      __ptr[3] = (short)puVar5;
      __ptr[4] = (short)((uint)puVar5 >> 0x10);
      *puVar5 = *param_3;
      goto _L0;
    }
    if (param_2 < 0x11) {
      if (8 < param_2) {
        if (param_2 != 9) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x18;
        puVar5 = (undefined1 *)malloc(1);
        __ptr[3] = (short)puVar5;
        __ptr[4] = (short)((uint)puVar5 >> 0x10);
        *puVar5 = *param_3;
        goto _L0;
      }
      if (6 < param_2) {
        *(undefined1 *)((int)__ptr + 3) = 5;
        *(undefined1 *)(__ptr + 1) = 0x20;
        puVar5 = (undefined1 *)malloc(1);
        __ptr[3] = (short)puVar5;
        __ptr[4] = (short)((uint)puVar5 >> 0x10);
        *puVar5 = *param_3;
        goto _L0;
      }
      if (param_2 != 1) {
        if (param_2 < 2) {
          if (param_2 != 0) goto _L0;
          *(undefined1 *)((int)__ptr + 3) = 5;
          *(undefined1 *)(__ptr + 1) = 0x29;
          puVar5 = (undefined1 *)malloc(2);
          __ptr[3] = (short)puVar5;
          __ptr[4] = (short)((uint)puVar5 >> 0x10);
          *puVar5 = *param_3;
          puVar5[1] = param_3[1];
          goto _L0;
        }
        if (param_2 == 2) goto _L0;
        if ((param_2 < 2) || (3 < (param_2 - 3 & 0xffff))) goto _L0;
      }
_L0:
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x29;
      puVar5 = (undefined1 *)malloc(2);
      __ptr[3] = (short)puVar5;
      __ptr[4] = (short)((uint)puVar5 >> 0x10);
      *puVar5 = *param_3;
      puVar5[1] = param_3[1];
      goto _L0;
    }
    if (param_2 == 0x19) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x28;
      puVar5 = (undefined1 *)malloc(1);
      __ptr[3] = (short)puVar5;
      __ptr[4] = (short)((uint)puVar5 >> 0x10);
      *puVar5 = *param_3;
      goto _L0;
    }
    if (param_2 < 0x1a) {
      if (param_2 < 0x13) {
        if (param_2 < 0x11) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 0x13;
        *(undefined1 *)(__ptr + 1) = 0x29;
        puVar5 = (undefined1 *)malloc(2);
        __ptr[3] = (short)puVar5;
        __ptr[4] = (short)((uint)puVar5 >> 0x10);
        *puVar5 = *param_3;
        puVar5[1] = param_3[1];
        goto _L0;
      }
      if ((param_2 - 0x13 & 0xffff) < 6) {
        *(undefined1 *)((int)__ptr + 3) = 3;
        *(undefined1 *)(__ptr + 1) = 0x29;
        puVar5 = (undefined1 *)malloc(2);
        __ptr[3] = (short)puVar5;
        __ptr[4] = (short)((uint)puVar5 >> 0x10);
        *puVar5 = *param_3;
        puVar5[1] = param_3[1];
        goto _L0;
      }
      goto _L0;
    }
    if (param_2 == 0x1a) {
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x18;
      puVar5 = (undefined1 *)malloc(1);
      __ptr[3] = (short)puVar5;
      __ptr[4] = (short)((uint)puVar5 >> 0x10);
      *puVar5 = *param_3;
      goto _L0;
    }
    if (param_2 != 0x1b) goto _L0;
_L0:
    *(undefined1 *)((int)__ptr + 3) = 3;
    *(undefined1 *)(__ptr + 1) = 0x30;
    puVar5 = (undefined1 *)malloc(1);
    __ptr[3] = (short)puVar5;
    __ptr[4] = (short)((uint)puVar5 >> 0x10);
    *puVar5 = *param_3;
    goto _L0;
  }
  if (param_2 == 0x32) {
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0xe2;
    puVar5 = (undefined1 *)malloc(4);
    __ptr[3] = (short)puVar5;
    __ptr[4] = (short)((uint)puVar5 >> 0x10);
    uVar1 = param_3[1];
    uVar2 = param_3[2];
    uVar3 = param_3[3];
    *puVar5 = *param_3;
    puVar5[1] = uVar1;
    puVar5[2] = uVar2;
    puVar5[3] = uVar3;
    goto _L0;
  }
  if (param_2 < 0x33) {
    if (param_2 == 0x25) {
      *(undefined1 *)((int)__ptr + 3) = 7;
      *(undefined1 *)(__ptr + 1) = 0x18;
      puVar5 = (undefined1 *)malloc(1);
      __ptr[3] = (short)puVar5;
      __ptr[4] = (short)((uint)puVar5 >> 0x10);
      *puVar5 = *param_3;
      goto _L0;
    }
    if (param_2 < 0x26) {
      if (param_2 != 0x20) {
        if (0x20 < param_2) {
          if (param_2 == 0x24) goto _L0;
          if (0x24 < param_2) goto _L0;
          if (0x22 < param_2) {
            if (param_2 != 0x23) goto _L0;
            goto _L0;
          }
          if (param_2 < 0x21) goto _L0;
_L0:
          *(undefined1 *)((int)__ptr + 3) = 1;
          *(undefined1 *)(__ptr + 1) = 0x20;
          puVar5 = (undefined1 *)malloc(1);
          __ptr[3] = (short)puVar5;
          __ptr[4] = (short)((uint)puVar5 >> 0x10);
          *puVar5 = *param_3;
          goto _L0;
        }
        if (param_2 == 0x1d) {
_L0:
          *(undefined1 *)((int)__ptr + 3) = 1;
          *(undefined1 *)(__ptr + 1) = 0x18;
          puVar5 = (undefined1 *)malloc(1);
          __ptr[3] = (short)puVar5;
          __ptr[4] = (short)((uint)puVar5 >> 0x10);
          *puVar5 = *param_3;
          goto _L0;
        }
        if (param_2 != 0x1e) goto _L0;
      }
    }
    else {
      if (param_2 == 0x29) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x19;
        puVar5 = (undefined1 *)malloc(2);
        __ptr[3] = (short)puVar5;
        __ptr[4] = (short)((uint)puVar5 >> 0x10);
        *puVar5 = *param_3;
        puVar5[1] = param_3[1];
        goto _L0;
      }
      if (param_2 < 0x29) goto _L0;
      if (param_2 != 0x30) {
        if (param_2 != 0x31) goto _L0;
        goto _L0;
      }
    }
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x30;
    puVar5 = (undefined1 *)malloc(1);
    __ptr[3] = (short)puVar5;
    __ptr[4] = (short)((uint)puVar5 >> 0x10);
    *puVar5 = *param_3;
  }
  else {
    if (param_2 == 0x41) {
_L0:
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x21;
      puVar5 = (undefined1 *)malloc(2);
      __ptr[3] = (short)puVar5;
      __ptr[4] = (short)((uint)puVar5 >> 0x10);
      *puVar5 = *param_3;
      puVar5[1] = param_3[1];
      goto _L0;
    }
    if (0x41 < param_2) {
      if (param_2 == 0x44) {
        *(undefined1 *)((int)__ptr + 3) = 3;
        *(undefined1 *)(__ptr + 1) = 0x1b;
        puVar5 = (undefined1 *)malloc(4);
        __ptr[3] = (short)puVar5;
        __ptr[4] = (short)((uint)puVar5 >> 0x10);
        uVar1 = param_3[1];
        uVar2 = param_3[2];
        uVar3 = param_3[3];
        *puVar5 = *param_3;
        puVar5[1] = uVar1;
        puVar5[2] = uVar2;
        puVar5[3] = uVar3;
        goto _L0;
      }
      if (param_2 < 0x45) {
        if (1 < (param_2 - 0x42 & 0xffff)) goto _L0;
      }
      else {
        if (param_2 == 0x46) goto _L0;
        if ((param_2 != 0x47) && (param_2 != 0x45)) goto _L0;
      }
      goto _L0;
    }
    if (param_2 != 0x37) {
      if (param_2 < 0x38) {
        if (param_2 != 0x34) {
          if (param_2 < 0x34) goto _L0;
          param_2 = param_2 - 0x35;
          goto joined_r0x0001501e;
        }
      }
      else if (param_2 != 0x3a) {
        if (0x3a < param_2) {
          if (param_2 != 0x40) goto _L0;
          goto _L0;
        }
        param_2 = param_2 - 0x38;
joined_r0x0001501e:
        if (1 < (param_2 & 0xffff)) {
_L0:
          uVar6 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_L0,uVar6,"ESP_ZIGBEE_ATTRIBUTE");
          free(__ptr);
          return 0x102;
        }
        goto _L0;
      }
    }
    *(undefined1 *)((int)__ptr + 3) = 3;
    *(undefined1 *)(__ptr + 1) = 0x20;
    puVar5 = (undefined1 *)malloc(1);
    __ptr[3] = (short)puVar5;
    __ptr[4] = (short)((uint)puVar5 >> 0x10);
    *puVar5 = *param_3;
  }
_L0:
  __ptr[2] = 0xffff;
  __ptr[5] = 0x201;
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar4 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar4 + 0xc) = __ptr;
  }
  return 0;
}

