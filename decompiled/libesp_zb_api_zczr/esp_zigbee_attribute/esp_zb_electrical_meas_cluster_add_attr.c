/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_electrical_meas_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010238) */
/* WARNING: Removing unreachable block (ram,0x00010240) */
/* WARNING: Removing unreachable block (ram,0x00010230) */
/* WARNING: Removing unreachable block (ram,0x0001029c) */
/* WARNING: Removing unreachable block (ram,0x000102a2) */

undefined4 esp_zb_electrical_meas_cluster_add_attr(ushort *param_1,uint param_2,void *param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  ushort *puVar3;
  ushort *puVar4;
  undefined2 *__ptr;
  size_t __size;
  void *__dest;
  undefined4 uVar5;
  undefined *puVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  
  if (param_2 == 0x700) {
    uVar8 = 3;
    uVar7 = 0x18;
    goto _L0;
  }
  if (param_2 < 0x701) {
    if (param_2 == 0x306) {
_L0:
      uVar8 = 5;
      uVar7 = 0x23;
      goto _L0;
    }
    if (param_2 < 0x307) {
      if (0x108 < param_2) {
        if (0x303 < param_2) {
          uVar8 = 5;
          uVar7 = 0x2b;
          goto _L0;
        }
        if (param_2 != 0x303) {
          uVar9 = 0x300;
          if (0x300 < param_2) goto _L0;
          if (0x205 < param_2) goto _L542;
          if (param_2 < 0x200) goto _L0;
        }
_L0:
        uVar8 = 5;
        goto _L0;
      }
      if (param_2 < 0x100) {
        uVar8 = 1;
        uVar7 = 0x1b;
        if (param_2 == 0) goto _L0;
        goto _L0;
      }
      uVar9 = 1 << (param_2 - 0x100 & 0x1f);
      if ((uVar9 & 0x1b6) == 0) {
        uVar7 = 0x29;
        uVar8 = 5;
        if ((uVar9 & 0x49) == 0) goto _L0;
        goto _L0;
      }
_L0:
      uVar8 = 1;
    }
    else {
      if (param_2 < 0x406) {
        if (0x403 < param_2) {
          uVar8 = 5;
          goto _L0;
        }
        if (0x401 < param_2) goto _L0;
        if (0x312 < param_2) {
          uVar10 = param_2 - 0x400;
          uVar9 = 1;
          goto _L539;
        }
      }
      else {
        if (0x50d < param_2) {
          if (param_2 < 0x518) {
            if (0x510 < param_2) goto _L0;
            if (param_2 != 0x50f) {
              uVar8 = 1;
              uVar7 = 0x29;
              if (param_2 != 0x510) {
                uVar8 = 5;
              }
              goto _L0;
            }
          }
          else {
            uVar10 = param_2 - 0x600;
            uVar9 = 5;
_L539:
            if (uVar9 < (uVar10 & 0xffff)) {
_L0:
              uVar5 = esp_log_timestamp();
              esp_log_write(1,0x10000,&_LC6,uVar5,0x10000);
              return 0x102;
            }
          }
          goto _L0;
        }
        if (0x50b < param_2) goto _L0;
        if (param_2 < 0x508) {
          if (param_2 < 0x506) {
            if (param_2 < 0x504) {
              uVar9 = 0x501;
              goto _L550;
            }
            uVar9 = 0x505;
            goto _L542;
          }
          goto _L0;
        }
        if (param_2 != 0x50b) {
          uVar9 = 0x508;
          goto _L537;
        }
      }
_L525:
      uVar8 = 5;
    }
_L0:
    uVar7 = 0x29;
  }
  else {
    if (param_2 == 0x90b) goto _L525;
    if (0x90b < param_2) {
      if (param_2 < 0xa08) {
        if (0xa05 < param_2) goto _L0;
        if (param_2 != 0x910) {
          if (0x910 < param_2) {
            if (0x917 < param_2) {
              if (0xa03 < param_2) {
                uVar9 = 0xa05;
                goto _L542;
              }
              uVar9 = 0xa01;
              goto _L550;
            }
            goto _L0;
          }
          if (param_2 != 0x90e) {
            uVar7 = 0x21;
            uVar8 = 5;
            if (param_2 == 0x90f) goto _L0;
            goto _L0;
          }
          goto _L525;
        }
      }
      else if (param_2 != 0xa10) {
        if (param_2 < 0xa11) {
          if (param_2 != 0xa0b) {
            if (param_2 < 0xa0c) {
              uVar9 = 0xa08;
              goto _L537;
            }
            if (param_2 != 0xa0e) {
              uVar8 = 5;
              uVar7 = 0x21;
              if (param_2 == 0xa0f) goto _L0;
              goto _L0;
            }
          }
          goto _L525;
        }
        if (6 < (param_2 - 0xa11 & 0xffff)) goto _L0;
_L0:
        uVar8 = 3;
        goto _L0;
      }
      uVar8 = 1;
_L0:
      uVar7 = 0x28;
      goto _L0;
    }
    if (param_2 < 0x80b) {
      if (param_2 < 0x807) {
        if (param_2 == 0x800) {
          uVar8 = 3;
          uVar7 = 0x19;
        }
        else {
          uVar7 = 0x29;
          uVar8 = 1;
          if ((param_2 < 0x801) && (1 < (param_2 - 0x701 & 0xffff))) goto _L0;
        }
        goto _L0;
      }
      uVar8 = 3;
      goto _L0;
    }
    if (param_2 < 0x908) {
      if (param_2 < 0x906) {
        uVar9 = 0x901;
        if (0x903 < param_2) {
          if (param_2 != 0x905) goto _L0;
          goto _L0;
        }
_L550:
        if (param_2 <= uVar9) {
_L542:
          if (param_2 != uVar9) goto _L0;
          goto _L0;
        }
        goto _L525;
      }
    }
    else {
      uVar9 = 0x908;
_L537:
      if (param_2 == uVar9) goto _L0;
    }
_L0:
    uVar8 = 1;
_L0:
    uVar7 = 0x21;
  }
_L0:
  if (param_1 == (ushort *)0x0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar5,0x10000);
  }
  else {
    uVar1 = *(ushort *)(*(int *)(param_1 + 6) + 10);
    puVar3 = param_1;
    if (uVar1 == 0xb04) {
      do {
        puVar4 = *(ushort **)(puVar3 + 6);
        if (puVar4 == (ushort *)0x0) {
          __ptr = (undefined2 *)malloc(0x10);
          if (__ptr == (undefined2 *)0x0) {
            return 0x102;
          }
          __size = esp_zb_zcl_get_attribute_size(uVar7,param_3);
          if (__size == 0xffff) {
_L0:
            free(__ptr);
            return 0x102;
          }
          __dest = (void *)0x0;
          if (__size != 0) {
            __dest = malloc(__size);
            if (__dest == (void *)0x0) goto _L0;
            memcpy(__dest,param_3,__size);
          }
          __ptr[2] = 0xffff;
          iVar11 = *(int *)(param_1 + 6);
          *(undefined1 *)((int)__ptr + 3) = uVar8;
          *(undefined1 *)(__ptr + 1) = uVar7;
          uVar2 = *(undefined2 *)(iVar11 + 10);
          __ptr[3] = (short)__dest;
          *__ptr = (short)param_2;
          __ptr[4] = (short)((uint)__dest >> 0x10);
          __ptr[5] = uVar2;
          *(undefined4 *)(__ptr + 6) = 0;
          *(undefined2 **)(puVar3 + 6) = __ptr;
          return 0;
        }
        puVar3 = puVar4;
      } while (*puVar4 != param_2);
      uVar5 = esp_log_timestamp();
      puVar6 = &_LC4;
    }
    else {
      uVar5 = esp_log_timestamp();
      puVar6 = &_LC2;
      param_2 = (uint)uVar1;
    }
    esp_log_write(1,0x10000,puVar6,uVar5,0x10000,param_2);
  }
  return 0x102;
}

