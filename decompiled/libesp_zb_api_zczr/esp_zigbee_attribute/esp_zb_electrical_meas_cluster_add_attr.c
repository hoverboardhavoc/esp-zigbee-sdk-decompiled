/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_electrical_meas_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001024e) */
/* WARNING: Removing unreachable block (ram,0x00010254) */
/* WARNING: Removing unreachable block (ram,0x00010268) */
/* WARNING: Removing unreachable block (ram,0x00010270) */
/* WARNING: Removing unreachable block (ram,0x00010278) */

undefined4 esp_zb_electrical_meas_cluster_add_attr(ushort *param_1,uint param_2,void *param_3)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 *__ptr;
  size_t __size;
  undefined4 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  ushort *puVar6;
  ushort *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  void *__dest;
  int iVar11;
  
  if (param_2 == 0x700) {
    uVar5 = 3;
    uVar4 = 0x18;
  }
  else if (param_2 < 0x701) {
    if (param_2 == 0x306) {
_L0:
      uVar5 = 5;
      uVar4 = 0x23;
    }
    else if (param_2 < 0x307) {
      if (param_2 < 0x109) {
        if (param_2 < 0x100) {
          uVar5 = 1;
          uVar4 = 0x1b;
          if (param_2 != 0) goto _L0;
        }
        else {
          uVar8 = 1 << (param_2 - 0x100 & 0x1f);
          if ((uVar8 & 0x1b6) != 0) {
_L0:
            uVar5 = 1;
            goto _L0;
          }
          uVar4 = 0x29;
          uVar5 = 5;
          if ((uVar8 & 0x49) == 0) goto _L0;
        }
      }
      else {
        if (param_2 < 0x304) {
          if (param_2 != 0x303) {
            uVar8 = 0x300;
            if (0x300 < param_2) goto _L0;
            if (0x205 < param_2) goto _L546;
            if (param_2 < 0x200) goto _L0;
          }
_L0:
          uVar5 = 5;
          goto _L0;
        }
        uVar5 = 5;
        uVar4 = 0x2b;
      }
    }
    else if (param_2 < 0x406) {
      if (param_2 < 0x404) {
        if (0x401 < param_2) goto _L0;
        if (0x312 < param_2) {
          uVar9 = param_2 - 0x400;
          uVar8 = 1;
          goto _L543;
        }
        goto _L529;
      }
      uVar5 = 5;
_L0:
      uVar4 = 0x28;
    }
    else {
      if (param_2 < 0x50e) {
        if (0x50b < param_2) goto _L0;
        if (param_2 < 0x508) {
          if (param_2 < 0x506) {
            if (param_2 < 0x504) {
              uVar8 = 0x501;
              goto _L554;
            }
            uVar8 = 0x505;
            goto _L546;
          }
          goto _L0;
        }
        if (param_2 != 0x50b) {
          uVar8 = 0x508;
          goto _L541;
        }
        goto _L529;
      }
      if (0x517 < param_2) {
        uVar9 = param_2 - 0x600;
        uVar8 = 5;
_L543:
        if (uVar8 < (uVar9 & 0xffff)) {
_L0:
          uVar3 = esp_log_timestamp();
          esp_log_write(1,0x10000,&_LC6,uVar3,0x10000);
          return 0x102;
        }
        goto _L0;
      }
      if (0x510 < param_2) goto _L0;
      if (param_2 == 0x50f) goto _L0;
      uVar5 = 1;
      uVar4 = 0x29;
      if (param_2 != 0x510) {
        uVar5 = 5;
      }
    }
  }
  else {
    if (param_2 == 0x90b) {
_L529:
      uVar5 = 5;
    }
    else {
      if (0x90b < param_2) {
        if (param_2 < 0xa08) {
          if (0xa05 < param_2) goto _L0;
          if (param_2 == 0x910) goto _L0;
          if (0x910 < param_2) {
            if (0x917 < param_2) {
              if (0xa03 < param_2) {
                uVar8 = 0xa05;
                goto _L546;
              }
              uVar8 = 0xa01;
              goto _L554;
            }
            goto _L0;
          }
          if (param_2 != 0x90e) {
            uVar4 = 0x21;
            uVar5 = 5;
            if (param_2 != 0x90f) goto _L0;
            goto _L0;
          }
        }
        else {
          if (param_2 == 0xa10) {
_L0:
            uVar5 = 1;
            goto _L0;
          }
          if (0xa10 < param_2) {
            if (6 < (param_2 - 0xa11 & 0xffff)) goto _L0;
_L0:
            uVar5 = 3;
            goto _L0;
          }
          if (param_2 != 0xa0b) {
            if (param_2 < 0xa0c) {
              uVar8 = 0xa08;
              goto _L541;
            }
            if (param_2 != 0xa0e) {
              uVar5 = 5;
              uVar4 = 0x21;
              if (param_2 != 0xa0f) goto _L0;
              goto _L0;
            }
          }
        }
        goto _L529;
      }
      if (0x80a < param_2) {
        if (param_2 < 0x908) {
          if (param_2 < 0x906) {
            uVar8 = 0x901;
            if (0x903 < param_2) {
              if (param_2 != 0x905) goto _L0;
              goto _L0;
            }
_L554:
            if (param_2 <= uVar8) {
_L546:
              if (param_2 != uVar8) goto _L0;
              goto _L0;
            }
            goto _L529;
          }
        }
        else {
          uVar8 = 0x908;
_L541:
          if (param_2 == uVar8) goto _L0;
        }
_L0:
        uVar5 = 1;
_L0:
        uVar4 = 0x21;
        goto _L0;
      }
      if (param_2 < 0x807) {
        if (param_2 == 0x800) {
          uVar5 = 3;
          uVar4 = 0x19;
        }
        else {
          uVar4 = 0x29;
          uVar5 = 1;
          if ((param_2 < 0x801) && (1 < (param_2 - 0x701 & 0xffff))) goto _L0;
        }
        goto _L0;
      }
      uVar5 = 3;
    }
_L0:
    uVar4 = 0x29;
  }
_L0:
  if (param_1 == (ushort *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar3,0x10000);
    return 0x102;
  }
  sVar1 = *(short *)(*(int *)(param_1 + 6) + 10);
  puVar6 = param_1;
  if (sVar1 == 0xb04) {
    while (puVar7 = *(ushort **)(puVar6 + 6), puVar7 != (ushort *)0x0) {
      puVar6 = puVar7;
      if (*puVar7 == param_2) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC4,uVar3,0x10000,param_2);
        return 0x102;
      }
    }
    iVar11 = 0;
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC2,uVar3,0x10000,sVar1);
    iVar11 = 0x102;
  }
  __ptr = (undefined2 *)malloc(0x10);
  if (__ptr == (undefined2 *)0x0) {
    return 0x102;
  }
  __size = esp_zb_zcl_get_attribute_size(uVar4,param_3);
  if (__size != 0xffff) {
    __dest = (void *)0x0;
    if (__size != 0) {
      __dest = malloc(__size);
      if (__dest == (void *)0x0) goto _L0;
      memcpy(__dest,param_3,__size);
    }
    __ptr[2] = 0xffff;
    iVar10 = *(int *)(param_1 + 6);
    *(undefined1 *)((int)__ptr + 3) = uVar5;
    *(undefined1 *)(__ptr + 1) = uVar4;
    uVar2 = *(undefined2 *)(iVar10 + 10);
    __ptr[3] = (short)__dest;
    *__ptr = (short)param_2;
    __ptr[4] = (short)((uint)__dest >> 0x10);
    __ptr[5] = uVar2;
    *(undefined4 *)(__ptr + 6) = 0;
    *(undefined2 **)(puVar6 + 6) = __ptr;
    if (iVar11 == 0) {
      return 0;
    }
  }
_L0:
  free(__ptr);
  return 0x102;
}

