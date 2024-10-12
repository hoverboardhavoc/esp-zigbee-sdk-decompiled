/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_ota_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010230) */
/* WARNING: Removing unreachable block (ram,0x00010238) */
/* WARNING: Removing unreachable block (ram,0x00010240) */

undefined4 esp_zb_ota_cluster_add_attr(ushort *param_1,uint param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  ushort uVar2;
  undefined2 uVar3;
  ushort *puVar4;
  ushort *puVar5;
  undefined2 *__ptr;
  size_t __size;
  undefined4 uVar6;
  undefined4 *puVar7;
  void *pvVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  undefined *puVar11;
  size_t sVar12;
  byte bVar13;
  int iVar14;
  uint uVar15;
  
  if (param_2 < 0xd) {
    if (param_2 == 0) {
      bVar13 = 1;
      sVar12 = 0xf0;
      goto _L0;
    }
    uVar15 = 1 << (param_2 & 0x1f);
    if ((uVar15 & 0x3a8) == 0) {
      if ((uVar15 & 0x416) == 0) {
        sVar12 = 0x30;
        bVar13 = 1;
        if ((uVar15 & 0x1840) == 0) goto _L0;
      }
      else {
        bVar13 = 1;
        sVar12 = 0x23;
      }
      goto _L0;
    }
  }
  else if (param_2 != 0xfff2) {
    if (0xfff2 < param_2) {
      if (param_2 == 0xfff3) {
        bVar13 = 1;
        sVar12 = 0x20;
        goto _L0;
      }
_L0:
      uVar6 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC6,uVar6,0x10000);
      return 0x102;
    }
    if (param_2 == 0xfff0) {
      if (param_3 == (undefined4 *)0x0) {
        uVar6 = 0x62e;
_L403:
        zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c"
                  ,uVar6);
      }
      puVar7 = (undefined4 *)malloc(0x10);
      bVar13 = *(byte *)(param_3 + 2);
      pvVar8 = calloc((uint)bVar13,8);
      puVar9 = (undefined1 *)malloc(1);
      uVar1 = *(undefined1 *)param_3;
      *puVar7 = puVar9;
      *puVar9 = uVar1;
      puVar10 = (undefined4 *)malloc(4);
      uVar6 = param_3[1];
      puVar7[1] = puVar10;
      *(byte *)(puVar7 + 2) = bVar13;
      *puVar10 = uVar6;
      puVar7[3] = pvVar8;
    }
    else {
      if (param_2 != 0xfff1) goto _L0;
      uVar6 = 0x617;
      if (param_3 == (undefined4 *)0x0) goto _L403;
      puVar7 = (undefined4 *)malloc(0x10);
      uVar3 = *(undefined2 *)param_3;
      *puVar7 = 0;
      *(undefined1 *)((int)puVar7 + 0xb) = 0;
      *(undefined2 *)(puVar7 + 1) = uVar3;
      *(undefined2 *)((int)puVar7 + 6) = uVar3;
      uVar3 = *(undefined2 *)((int)param_3 + 2);
      *(undefined1 *)(puVar7 + 3) = 0;
      *(undefined2 *)(puVar7 + 2) = uVar3;
      *(undefined1 *)((int)puVar7 + 10) = *(undefined1 *)(param_3 + 1);
    }
    bVar13 = 0x40;
    sVar12 = 0x10;
    param_3 = puVar7;
    goto _L0;
  }
  bVar13 = 1;
  sVar12 = 0x21;
_L0:
  if (param_1 == (ushort *)0x0) {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar6,0x10000);
  }
  else {
    uVar2 = *(ushort *)(*(int *)(param_1 + 6) + 10);
    puVar4 = param_1;
    if (uVar2 == 0x19) {
      do {
        puVar5 = *(ushort **)(puVar4 + 6);
        if (puVar5 == (ushort *)0x0) {
          __ptr = (undefined2 *)malloc(0x10);
          if (__ptr == (undefined2 *)0x0) {
            return 0x102;
          }
          if ((bVar13 & 0x40) == 0) {
_L0:
            __size = esp_zb_zcl_get_attribute_size(sVar12,param_3);
            if (__size == 0xffff) goto _L0;
          }
          else {
            __size = sVar12;
            if (param_3 == (undefined4 *)0x0) {
              zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c"
                        ,0x6c);
              goto _L0;
            }
          }
          pvVar8 = (void *)0x0;
          if (__size != 0) {
            pvVar8 = malloc(__size);
            if (pvVar8 == (void *)0x0) {
_L0:
              free(__ptr);
              return 0x102;
            }
            memcpy(pvVar8,param_3,__size);
          }
          __ptr[2] = 0xffff;
          iVar14 = *(int *)(param_1 + 6);
          *(byte *)((int)__ptr + 3) = bVar13;
          *(char *)(__ptr + 1) = (char)sVar12;
          uVar3 = *(undefined2 *)(iVar14 + 10);
          __ptr[3] = (short)pvVar8;
          *__ptr = (short)param_2;
          __ptr[4] = (short)((uint)pvVar8 >> 0x10);
          __ptr[5] = uVar3;
          *(undefined4 *)(__ptr + 6) = 0;
          *(undefined2 **)(puVar4 + 6) = __ptr;
          return 0;
        }
        puVar4 = puVar5;
      } while (*puVar5 != param_2);
      uVar6 = esp_log_timestamp();
      puVar11 = &_LC4;
    }
    else {
      uVar6 = esp_log_timestamp();
      puVar11 = &_LC2;
      param_2 = (uint)uVar2;
    }
    esp_log_write(1,0x10000,puVar11,uVar6,0x10000,param_2);
  }
  return 0x102;
}

