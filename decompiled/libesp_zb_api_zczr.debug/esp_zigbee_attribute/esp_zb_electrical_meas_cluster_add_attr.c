/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_electrical_meas_cluster_add_attr
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
  uint uVar4;
  undefined2 *__ptr;
  int iVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar5 = esp_zb_attr_list_get_tail(param_1,0xb04,param_2,aiStack_24);
  if (aiStack_24[0] != 0) {
    free(__ptr);
    return aiStack_24[0];
  }
  *__ptr = (short)param_2;
  if (param_2 == 0x700) {
    *(undefined1 *)((int)__ptr + 3) = 3;
    *(undefined1 *)(__ptr + 1) = 0x18;
    puVar6 = (undefined1 *)malloc(1);
    __ptr[3] = (short)puVar6;
    __ptr[4] = (short)((uint)puVar6 >> 0x10);
    *puVar6 = *param_3;
    goto _L0;
  }
  if (param_2 < 0x701) {
    if (param_2 == 0x306) {
_L0:
      *(undefined1 *)((int)__ptr + 3) = 5;
      *(undefined1 *)(__ptr + 1) = 0x23;
      puVar6 = (undefined1 *)malloc(4);
      __ptr[3] = (short)puVar6;
      __ptr[4] = (short)((uint)puVar6 >> 0x10);
      uVar1 = param_3[1];
      uVar2 = param_3[2];
      uVar3 = param_3[3];
      *puVar6 = *param_3;
      puVar6[1] = uVar1;
      puVar6[2] = uVar2;
      puVar6[3] = uVar3;
      goto _L0;
    }
    if (param_2 < 0x307) {
      if (param_2 < 0x109) {
        if (param_2 < 0x100) {
          if (param_2 == 0) {
            *(undefined1 *)((int)__ptr + 3) = 1;
            *(undefined1 *)(__ptr + 1) = 0x1b;
            puVar6 = (undefined1 *)malloc(4);
            __ptr[3] = (short)puVar6;
            __ptr[4] = (short)((uint)puVar6 >> 0x10);
            uVar1 = param_3[1];
            uVar2 = param_3[2];
            uVar3 = param_3[3];
            *puVar6 = *param_3;
            puVar6[1] = uVar1;
            puVar6[2] = uVar2;
            puVar6[3] = uVar3;
            goto _L0;
          }
          goto _L0;
        }
        uVar4 = 1 << (param_2 - 0x100 & 0x1f);
        if ((uVar4 & 0x1b6) != 0) goto _L0;
        if ((uVar4 & 0x49) == 0) goto _L0;
        goto _L0;
      }
      if (0x305 < param_2) goto _L0;
      if (0x303 < param_2) {
        *(undefined1 *)((int)__ptr + 3) = 5;
        *(undefined1 *)(__ptr + 1) = 0x2b;
        puVar6 = (undefined1 *)malloc(4);
        __ptr[3] = (short)puVar6;
        __ptr[4] = (short)((uint)puVar6 >> 0x10);
        uVar1 = param_3[1];
        uVar2 = param_3[2];
        uVar3 = param_3[3];
        *puVar6 = *param_3;
        puVar6[1] = uVar1;
        puVar6[2] = uVar2;
        puVar6[3] = uVar3;
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
        puVar6 = (undefined1 *)malloc(1);
        __ptr[3] = (short)puVar6;
        __ptr[4] = (short)((uint)puVar6 >> 0x10);
        *puVar6 = *param_3;
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
        puVar6 = (undefined1 *)malloc(2);
        __ptr[3] = (short)puVar6;
        __ptr[4] = (short)((uint)puVar6 >> 0x10);
        *puVar6 = *param_3;
        puVar6[1] = param_3[1];
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
            goto joined_r0x00014d76;
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
        puVar6 = (undefined1 *)malloc(2);
        __ptr[3] = (short)puVar6;
        __ptr[4] = (short)((uint)puVar6 >> 0x10);
        *puVar6 = *param_3;
        puVar6[1] = param_3[1];
        goto _L0;
      }
      if (param_2 == 0xa0b) {
_L0:
        *(undefined1 *)((int)__ptr + 3) = 5;
        *(undefined1 *)(__ptr + 1) = 0x29;
        puVar6 = (undefined1 *)malloc(2);
        __ptr[3] = (short)puVar6;
        __ptr[4] = (short)((uint)puVar6 >> 0x10);
        *puVar6 = *param_3;
        puVar6[1] = param_3[1];
        goto _L0;
      }
      if (param_2 < 0xa0c) {
        if (param_2 != 0xa08) {
          if (param_2 < 0xa08) goto _L0;
          param_2 = param_2 - 0xa09;
          goto joined_r0x00014c16;
        }
      }
      else {
        if (param_2 == 0xa0e) goto _L0;
        if (param_2 < 0xa0f) {
          param_2 = param_2 - 0xa0c;
          goto joined_r0x00014d76;
        }
        if (param_2 != 0xa0f) goto _L0;
      }
      goto _L0;
    }
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x28;
    puVar6 = (undefined1 *)malloc(1);
    __ptr[3] = (short)puVar6;
    __ptr[4] = (short)((uint)puVar6 >> 0x10);
    *puVar6 = *param_3;
    goto _L0;
  }
  if (param_2 < 0x80b) {
    if (0x806 < param_2) {
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x29;
      puVar6 = (undefined1 *)malloc(2);
      __ptr[3] = (short)puVar6;
      __ptr[4] = (short)((uint)puVar6 >> 0x10);
      *puVar6 = *param_3;
      puVar6[1] = param_3[1];
      goto _L0;
    }
    if (param_2 == 0x800) {
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x19;
      puVar6 = (undefined1 *)malloc(1);
      __ptr[3] = (short)puVar6;
      __ptr[4] = (short)((uint)puVar6 >> 0x10);
      *puVar6 = *param_3;
      goto _L0;
    }
    if (0x800 < param_2) {
      if (5 < (param_2 - 0x801 & 0xffff)) goto _L0;
      goto _L0;
    }
    param_2 = param_2 - 0x701;
joined_r0x00014d76:
    if (1 < (param_2 & 0xffff)) {
_L0:
      uVar7 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_L0,uVar7,0x10000);
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
      puVar6 = (undefined1 *)malloc(2);
      __ptr[3] = (short)puVar6;
      __ptr[4] = (short)((uint)puVar6 >> 0x10);
      *puVar6 = *param_3;
      puVar6[1] = param_3[1];
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
joined_r0x00014c16:
    if (1 < (param_2 & 0xffff)) goto _L0;
    goto _L0;
  }
_L0:
  *(undefined1 *)((int)__ptr + 3) = 5;
  *(undefined1 *)(__ptr + 1) = 0x21;
  puVar6 = (undefined1 *)malloc(2);
  __ptr[3] = (short)puVar6;
  __ptr[4] = (short)((uint)puVar6 >> 0x10);
  *puVar6 = *param_3;
  puVar6[1] = param_3[1];
_L0:
  __ptr[2] = 0xffff;
  __ptr[5] = 0xb04;
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar5 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar5 + 0xc) = __ptr;
  }
  return 0;
}

