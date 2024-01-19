/*
 * Last changed at upstream commit 0c62d9f04d6c4a739fd0a010d54749e3cd6ae209
 * https://github.com/espressif/esp-zigbee-sdk/commit/0c62d9f04d6c4a739fd0a010d54749e3cd6ae209
 * Upstream date: 2024-01-19 19:10:32 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.9(b7135493)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_electrical_meas_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */

int esp_zb_electrical_meas_cluster_add_attr(int param_1,uint param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined2 *__ptr;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar4 = esp_zb_attr_list_get_tail(param_1,0xb04,param_2,aiStack_24);
  if (aiStack_24[0] != 0) {
    free(__ptr);
    return aiStack_24[0];
  }
  *__ptr = (short)param_2;
  if (param_2 == 0x700) {
    *(undefined1 *)((int)__ptr + 3) = 3;
    *(undefined1 *)(__ptr + 1) = 0x18;
    puVar5 = (undefined1 *)malloc(1);
    __ptr[3] = (short)puVar5;
    __ptr[4] = (short)((uint)puVar5 >> 0x10);
    *puVar5 = *param_3;
    goto _L0;
  }
  if (param_2 < 0x701) {
    if (param_2 == 0x306) {
_L0:
      *(undefined1 *)((int)__ptr + 3) = 5;
      *(undefined1 *)(__ptr + 1) = 0x23;
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
    if (param_2 < 0x307) {
      if (param_2 < 0x109) {
        if (param_2 < 0x100) {
          if (param_2 == 0) {
            *(undefined1 *)((int)__ptr + 3) = 1;
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
          goto _L0;
        }
        uVar7 = 1 << (param_2 - 0x100 & 0x1f);
        if ((uVar7 & 0x1b6) != 0) goto _L0;
        if ((uVar7 & 0x49) == 0) goto _L0;
        goto _L0;
      }
      if (0x305 < param_2) goto _L0;
      if (0x303 < param_2) {
        *(undefined1 *)((int)__ptr + 3) = 5;
        *(undefined1 *)(__ptr + 1) = 0x2b;
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
      if (param_2 < 0x303) {
        if (0x300 < param_2) goto _L0;
        if (param_2 < 0x206) {
          if (param_2 < 0x200) goto _L0;
        }
        else if (param_2 != 0x300) goto _L0;
      }
      else if (param_2 != 0x303) goto _L0;
    }
    else if (param_2 < 0x406) {
      if (0x403 < param_2) {
        *(undefined1 *)((int)__ptr + 3) = 5;
        *(undefined1 *)(__ptr + 1) = 0x28;
        puVar5 = (undefined1 *)malloc(1);
        __ptr[3] = (short)puVar5;
        __ptr[4] = (short)((uint)puVar5 >> 0x10);
        *puVar5 = *param_3;
        goto _L0;
      }
      if (0x403 < param_2) goto _L0;
      if (0x401 < param_2) goto _L0;
      if (param_2 < 0x313) {
        if (param_2 < 0x307) goto _L0;
        goto _L0;
      }
      if (1 < (param_2 - 0x400 & 0xffff)) goto _L0;
    }
    else if (param_2 < 0x50e) {
      if (0x50b < param_2) {
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
      if (param_2 < 0x508) {
        if (0x505 < param_2) goto _L0;
        if (param_2 < 0x504) {
          if (0x501 < param_2) goto _L0;
          if (param_2 != 0x501) goto _L0;
        }
        else if (param_2 != 0x505) goto _L0;
      }
      else {
        if (0x50a < param_2) {
          if (param_2 != 0x50b) goto _L0;
          goto _L0;
        }
        if (0x508 < param_2) goto _L0;
        if (param_2 != 0x508) goto _L0;
      }
    }
    else if (param_2 < 0x518) {
      if (0x510 < param_2) goto _L0;
      if (param_2 != 0x50f) {
        if (param_2 != 0x510) {
          if (param_2 != 0x50e) goto _L0;
          goto _L0;
        }
        goto _L0;
      }
    }
    else if (5 < (param_2 - 0x600 & 0xffff)) goto _L0;
    goto _L0;
  }
  if (param_2 == 0x90b) goto _L0;
  if (0x90b < param_2) {
    if (param_2 < 0xa08) {
      if (0xa05 < param_2) goto _L0;
      if (param_2 != 0x910) {
        if (param_2 < 0x911) {
          if (param_2 == 0x90e) goto _L0;
          if (param_2 < 0x90f) {
            param_2 = param_2 - 0x90c;
            goto joined_r0x000147ce;
          }
          if (param_2 != 0x90f) goto _L0;
        }
        else {
          if (param_2 < 0x918) {
            if (param_2 < 0x911) goto _L0;
            goto _L0;
          }
          if (param_2 < 0xa04) {
            if (0xa01 < param_2) goto _L0;
            if (param_2 != 0xa01) goto _L0;
          }
          else if (param_2 != 0xa05) goto _L0;
        }
        goto _L0;
      }
    }
    else if (param_2 != 0xa10) {
      if (0xa10 < param_2) {
        if (6 < (param_2 - 0xa11 & 0xffff)) goto _L0;
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
      if (param_2 == 0xa0b) {
_L0:
        *(undefined1 *)((int)__ptr + 3) = 5;
        *(undefined1 *)(__ptr + 1) = 0x29;
        puVar5 = (undefined1 *)malloc(2);
        __ptr[3] = (short)puVar5;
        __ptr[4] = (short)((uint)puVar5 >> 0x10);
        *puVar5 = *param_3;
        puVar5[1] = param_3[1];
        goto _L0;
      }
      if (param_2 < 0xa0c) {
        if (param_2 != 0xa08) {
          if (param_2 < 0xa08) goto _L0;
          param_2 = param_2 - 0xa09;
          goto joined_r0x0001471e;
        }
      }
      else {
        if (param_2 == 0xa0e) goto _L0;
        if (param_2 < 0xa0f) {
          param_2 = param_2 - 0xa0c;
          goto joined_r0x000147ce;
        }
        if (param_2 != 0xa0f) goto _L0;
      }
      goto _L0;
    }
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x28;
    puVar5 = (undefined1 *)malloc(1);
    __ptr[3] = (short)puVar5;
    __ptr[4] = (short)((uint)puVar5 >> 0x10);
    *puVar5 = *param_3;
    goto _L0;
  }
  if (param_2 < 0x80b) {
    if (0x806 < param_2) {
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x29;
      puVar5 = (undefined1 *)malloc(2);
      __ptr[3] = (short)puVar5;
      __ptr[4] = (short)((uint)puVar5 >> 0x10);
      *puVar5 = *param_3;
      puVar5[1] = param_3[1];
      goto _L0;
    }
    if (param_2 == 0x800) {
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x19;
      puVar5 = (undefined1 *)malloc(1);
      __ptr[3] = (short)puVar5;
      __ptr[4] = (short)((uint)puVar5 >> 0x10);
      *puVar5 = *param_3;
      goto _L0;
    }
    if (0x800 < param_2) {
      if (5 < (param_2 - 0x801 & 0xffff)) goto _L0;
      goto _L0;
    }
    param_2 = param_2 - 0x701;
joined_r0x000147ce:
    if (1 < (param_2 & 0xffff)) {
_L0:
      uVar6 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_L0,uVar6,"ESP_ZIGBEE_ATTRIBUTE");
      free(__ptr);
      return 0x102;
    }
    goto _L0;
  }
  if (param_2 < 0x908) {
    if (0x905 < param_2) {
_L0:
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x21;
      puVar5 = (undefined1 *)malloc(2);
      __ptr[3] = (short)puVar5;
      __ptr[4] = (short)((uint)puVar5 >> 0x10);
      *puVar5 = *param_3;
      puVar5[1] = param_3[1];
      goto _L0;
    }
    if (param_2 < 0x904) {
      if (0x901 < param_2) goto _L0;
      if (param_2 != 0x901) goto _L0;
    }
    else if (param_2 != 0x905) goto _L0;
  }
  else if (param_2 != 0x908) {
    if (param_2 < 0x908) goto _L0;
    param_2 = param_2 - 0x909;
joined_r0x0001471e:
    if (1 < (param_2 & 0xffff)) goto _L0;
    goto _L0;
  }
_L0:
  *(undefined1 *)((int)__ptr + 3) = 5;
  *(undefined1 *)(__ptr + 1) = 0x21;
  puVar5 = (undefined1 *)malloc(2);
  __ptr[3] = (short)puVar5;
  __ptr[4] = (short)((uint)puVar5 >> 0x10);
  *puVar5 = *param_3;
  puVar5[1] = param_3[1];
_L0:
  __ptr[2] = 0xffff;
  __ptr[5] = 0xb04;
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar4 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar4 + 0xc) = __ptr;
  }
  return 0;
}

