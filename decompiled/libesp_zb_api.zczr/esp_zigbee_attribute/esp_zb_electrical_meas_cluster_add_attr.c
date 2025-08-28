/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_attribute.o -> esp_zb_electrical_meas_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010256) */
/* WARNING: Removing unreachable block (ram,0x0001025c) */
/* WARNING: Removing unreachable block (ram,0x00010260) */
/* WARNING: Removing unreachable block (ram,0x0001028e) */

undefined4 esp_zb_electrical_meas_cluster_add_attr(ushort *param_1,uint param_2,void *param_3)

{
  undefined2 uVar1;
  ushort *puVar2;
  undefined2 *__ptr;
  size_t __size;
  void *__dest;
  undefined4 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  
  if (param_2 < 0x518) {
    if (0x510 < param_2) {
_L0:
      uVar5 = 3;
_L0:
      uVar4 = 0x21;
      goto _L0;
    }
    if (param_2 == 0x306) {
_L0:
      uVar5 = 5;
      uVar4 = 0x23;
      goto _L0;
    }
    if (param_2 < 0x307) {
      if (0x108 < param_2) {
        if (0x303 < param_2) {
          uVar5 = 5;
          uVar4 = 0x2b;
          goto _L0;
        }
        if (param_2 != 0x303) {
          uVar6 = 0x300;
          if (param_2 < 0x301) {
            if (param_2 < 0x206) {
              uVar6 = 0x1ff;
              goto _L536;
            }
            goto _L540;
          }
          goto _L0;
        }
        goto _L0;
      }
      if (param_2 < 0x100) {
        uVar5 = 1;
        uVar4 = 0x1b;
        if (param_2 == 0) goto _L0;
        goto _L0;
      }
      uVar6 = 1 << (param_2 - 0x100 & 0x1f);
      if ((uVar6 & 0x1b6) != 0) goto _L0;
      if ((uVar6 & 0x49) == 0) goto _L0;
    }
    else if (param_2 < 0x406) {
      if (0x403 < param_2) {
        uVar5 = 5;
_L0:
        uVar4 = 0x28;
        goto _L0;
      }
      if (0x401 < param_2) goto _L0;
      if (0x312 < param_2) {
        if (1 < (param_2 - 0x400 & 0xffff)) goto _L0;
        goto _L0;
      }
    }
    else if (param_2 != 0x50b) {
      if (param_2 < 0x50c) {
        if (param_2 < 0x508) {
          if (0x505 < param_2) {
_L0:
            uVar5 = 1;
            goto _L0;
          }
          if (param_2 < 0x504) {
            uVar6 = 0x501;
            if (0x501 < param_2) goto _L0;
          }
          else {
            uVar6 = 0x505;
          }
_L540:
          if (param_2 != uVar6) {
_L0:
            uVar3 = esp_log_timestamp();
            esp_log_write(1,0x10000,&_LC5,uVar3,0x10000);
            return 0x102;
          }
        }
        else if (param_2 != 0x508) goto _L0;
_L0:
        uVar5 = 5;
        goto _L0;
      }
      if (param_2 == 0x510) goto _L0;
      if (param_2 != 0x50e) {
        if (param_2 != 0x50f) goto _L0;
        goto _L0;
      }
    }
_L0:
    uVar5 = 5;
  }
  else {
    if (0x80a < param_2) {
      if (param_2 == 0xa01) goto _L0;
      if (param_2 < 0xa02) {
        if (param_2 != 0x90e) {
          if (param_2 < 0x90f) {
            if (param_2 != 0x908) {
              if (0x908 < param_2) {
                if (param_2 == 0x90b) goto _L0;
                if (0x90b < param_2) goto _L0;
                goto _L0;
              }
              if (param_2 != 0x905) {
                if (0x905 < param_2) goto _L0;
                if (param_2 != 0x901) {
                  if (1 < (param_2 - 0x902 & 0xffff)) goto _L0;
                  goto _L0;
                }
              }
            }
          }
          else {
            if (param_2 == 0x910) {
_L0:
              uVar5 = 1;
              goto _L0;
            }
            if (0x910 < param_2) {
              if (6 < (param_2 - 0x911 & 0xffff)) goto _L0;
              goto _L0;
            }
          }
          goto _L0;
        }
      }
      else if (param_2 != 0xa0e) {
        if (0xa0e < param_2) {
          if (param_2 == 0xa10) goto _L0;
          if (0xa10 < param_2) {
            uVar5 = 3;
            uVar4 = 0x21;
            if (6 < (param_2 - 0xa11 & 0xffff)) goto _L0;
            goto _L0;
          }
          goto _L0;
        }
        if (param_2 < 0xa0b) {
          if (param_2 < 0xa09) {
            if (param_2 == 0xa08) goto _L0;
            if (param_2 < 0xa06) {
              if (0xa03 < param_2) {
                uVar5 = 5;
                uVar4 = 0x21;
                if (param_2 != 0xa05) goto _L0;
                goto _L0;
              }
              goto _L0;
            }
          }
          goto _L0;
        }
        if (param_2 != 0xa0b) goto _L0;
      }
      goto _L0;
    }
    if (param_2 < 0x807) {
      if (param_2 < 0x703) {
        if (param_2 < 0x701) {
          if (0x605 < param_2) {
            uVar5 = 3;
            uVar4 = 0x18;
            if (param_2 != 0x700) goto _L0;
            goto _L0;
          }
          uVar6 = 0x5ff;
_L536:
          if (param_2 <= uVar6) goto _L0;
          goto _L0;
        }
      }
      else {
        if (param_2 == 0x800) {
          uVar5 = 3;
          uVar4 = 0x19;
          goto _L0;
        }
        if (5 < (param_2 - 0x801 & 0xffff)) goto _L0;
      }
_L0:
      uVar5 = 1;
    }
    else {
      uVar5 = 3;
    }
  }
  uVar4 = 0x29;
_L0:
  if ((param_1 == (ushort *)0x0) || (*(int *)(param_1 + 6) == 0)) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar3,0x10000);
  }
  else {
    puVar8 = param_1;
    if (*(short *)(*(int *)(param_1 + 6) + 10) == 0xb04) {
      do {
        puVar2 = *(ushort **)(puVar8 + 6);
        if (puVar2 == (ushort *)0x0) {
          __ptr = (undefined2 *)malloc(0x10);
          if (__ptr == (undefined2 *)0x0) {
            return 0x102;
          }
          __size = esp_zb_zcl_get_attribute_size(uVar4,param_3);
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
          iVar7 = *(int *)(param_1 + 6);
          *(undefined1 *)((int)__ptr + 3) = uVar5;
          *(undefined1 *)(__ptr + 1) = uVar4;
          uVar1 = *(undefined2 *)(iVar7 + 10);
          __ptr[3] = (short)__dest;
          *__ptr = (short)param_2;
          __ptr[4] = (short)((uint)__dest >> 0x10);
          __ptr[2] = 0xffff;
          __ptr[5] = uVar1;
          *(undefined4 *)(__ptr + 6) = 0;
          *(undefined2 **)(puVar8 + 6) = __ptr;
          return 0;
        }
        puVar8 = puVar2;
      } while ((*puVar2 != param_2) || (puVar2[2] != 0xffff));
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC3,uVar3,0x10000,param_2);
    }
    else {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC2,uVar3,0x10000,*(undefined2 *)(*(int *)(param_1 + 6) + 10),0xb04)
      ;
    }
  }
  return 0x102;
}

