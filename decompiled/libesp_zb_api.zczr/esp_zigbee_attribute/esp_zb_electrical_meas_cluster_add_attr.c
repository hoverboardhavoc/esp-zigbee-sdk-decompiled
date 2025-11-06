/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_attribute.o -> esp_zb_electrical_meas_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010230) */
/* WARNING: Removing unreachable block (ram,0x00010236) */
/* WARNING: Removing unreachable block (ram,0x0001023a) */
/* WARNING: Removing unreachable block (ram,0x00010268) */

undefined4 esp_zb_electrical_meas_cluster_add_attr(ushort *param_1,uint param_2,void *param_3)

{
  undefined2 uVar1;
  ushort *puVar2;
  ushort *puVar3;
  undefined2 *__ptr;
  size_t __size;
  void *__dest;
  undefined4 uVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined1 uVar7;
  int iVar8;
  
  if (param_2 < 0x518) {
    if (0x510 < param_2) {
_L0:
      uVar7 = 3;
_L0:
      uVar5 = 0x21;
      goto _L0;
    }
    if (param_2 == 0x306) {
_L0:
      uVar7 = 5;
      uVar5 = 0x23;
      goto _L0;
    }
    if (param_2 < 0x307) {
      if (0x108 < param_2) {
        if (0x303 < param_2) {
          uVar7 = 5;
          uVar5 = 0x2b;
          goto _L0;
        }
        if (param_2 != 0x303) {
          uVar6 = 0x300;
          if (0x300 < param_2) goto _L0;
          if (param_2 < 0x206) {
            uVar6 = 0x1ff;
            goto _L534;
          }
_L467:
          if (param_2 != uVar6) {
_L0:
            uVar4 = esp_log_timestamp();
            esp_log(1,0x10000,"E (%lu) %s: incorrect/unsupported attribute_id!\n",uVar4,0x10000);
            return 0x102;
          }
        }
        goto _L0;
      }
      if (param_2 < 0x100) {
        uVar7 = 1;
        uVar5 = 0x1b;
        if (param_2 == 0) goto _L0;
        goto _L0;
      }
      uVar7 = 1;
      uVar6 = 1 << (param_2 - 0x100 & 0x1f);
      if ((uVar6 & 0x1b6) != 0) goto _L0;
      if ((uVar6 & 0x49) == 0) goto _L0;
    }
    else if (param_2 < 0x406) {
      if (0x403 < param_2) {
        uVar7 = 5;
_L0:
        uVar5 = 0x28;
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
          uVar6 = 0x505;
          if (param_2 < 0x506) {
            if ((0x503 < param_2) || (uVar6 = 0x501, param_2 < 0x502)) goto _L467;
            goto _L0;
          }
        }
        else if (param_2 == 0x508) goto _L0;
_L0:
        uVar7 = 1;
        goto _L0;
      }
      if (param_2 == 0x510) goto _L0;
      if (param_2 != 0x50e) {
        if (param_2 != 0x50f) goto _L0;
        goto _L0;
      }
    }
_L0:
    uVar7 = 5;
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
              uVar7 = 1;
              goto _L0;
            }
            if (0x910 < param_2) {
              if (6 < (param_2 - 0x911 & 0xffff)) goto _L0;
              goto _L0;
            }
          }
_L0:
          uVar7 = 5;
          goto _L0;
        }
      }
      else if (param_2 != 0xa0e) {
        if (0xa0e < param_2) {
          if (param_2 == 0xa10) goto _L0;
          if (0xa10 < param_2) {
            uVar7 = 3;
            uVar5 = 0x21;
            if (6 < (param_2 - 0xa11 & 0xffff)) goto _L0;
            goto _L0;
          }
          goto _L0;
        }
        if (param_2 < 0xa0b) {
          if (param_2 < 0xa09) {
            if (param_2 == 0xa08) goto _L0;
            uVar6 = 0xa05;
            if (param_2 < 0xa06) {
              if (0xa03 < param_2) {
                uVar7 = 5;
                uVar5 = 0x21;
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
        uVar6 = 0x700;
        if (param_2 < 0x701) {
          if (0x605 < param_2) {
            uVar7 = 3;
            uVar5 = 0x18;
_L0:
            if (param_2 != uVar6) goto _L0;
            goto _L0;
          }
          uVar6 = 0x5ff;
_L534:
          if (param_2 <= uVar6) goto _L0;
          goto _L0;
        }
      }
      else {
        if (param_2 == 0x800) {
          uVar7 = 3;
          uVar5 = 0x19;
          goto _L0;
        }
        if (5 < (param_2 - 0x801 & 0xffff)) goto _L0;
      }
_L0:
      uVar7 = 1;
    }
    else {
      uVar7 = 3;
    }
  }
_L0:
  uVar5 = 0x29;
_L0:
  if ((param_1 == (ushort *)0x0) || (*(int *)(param_1 + 6) == 0)) {
    uVar4 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: Uninitialized attribute linked list!\n",uVar4,0x10000);
  }
  else {
    puVar2 = param_1;
    if (*(short *)(*(int *)(param_1 + 6) + 10) == 0xb04) {
      do {
        puVar3 = *(ushort **)(puVar2 + 6);
        if (puVar3 == (ushort *)0x0) {
          __ptr = (undefined2 *)malloc(0x10);
          if (__ptr == (undefined2 *)0x0) {
            return 0x102;
          }
          __size = esp_zb_zcl_get_attribute_size(uVar5,param_3);
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
          iVar8 = *(int *)(param_1 + 6);
          *(undefined1 *)((int)__ptr + 3) = uVar7;
          *(undefined1 *)(__ptr + 1) = uVar5;
          uVar1 = *(undefined2 *)(iVar8 + 10);
          __ptr[3] = (short)__dest;
          *__ptr = (short)param_2;
          __ptr[4] = (short)((uint)__dest >> 0x10);
          __ptr[2] = 0xffff;
          __ptr[5] = uVar1;
          *(undefined4 *)(__ptr + 6) = 0;
          *(undefined2 **)(puVar2 + 6) = __ptr;
          return 0;
        }
        puVar2 = puVar3;
      } while ((*puVar3 != param_2) || (puVar3[2] != 0xffff));
      uVar4 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: The requested add attribute ID:0x%x is already existed\n",uVar4
              ,0x10000,param_2);
    }
    else {
      uVar4 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: Wrong cluster(0x%04x) to add attribute, expect 0x%04x\n",uVar4,
              0x10000,*(undefined2 *)(*(int *)(param_1 + 6) + 10),0xb04);
    }
  }
  return 0x102;
}

