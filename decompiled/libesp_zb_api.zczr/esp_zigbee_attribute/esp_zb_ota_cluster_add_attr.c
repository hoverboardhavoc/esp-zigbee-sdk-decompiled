/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_attribute.o -> esp_zb_ota_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001028e) */

undefined4 esp_zb_ota_cluster_add_attr(ushort *param_1,uint param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  ushort *puVar3;
  undefined2 *__ptr;
  size_t __size;
  undefined4 uVar4;
  undefined4 *puVar5;
  void *pvVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  size_t sVar9;
  byte bVar10;
  int iVar11;
  uint uVar12;
  ushort *puVar13;
  
  if (param_2 < 0xd) {
    if (param_2 == 0) {
      bVar10 = 1;
      sVar9 = 0xf0;
      goto _L0;
    }
    uVar12 = 1 << (param_2 & 0x1f);
    if ((uVar12 & 0x3a8) == 0) {
      if ((uVar12 & 0x416) == 0) {
        if ((uVar12 >> 6 & 0x61) == 0) goto _L0;
        bVar10 = 1;
        sVar9 = 0x30;
      }
      else {
        bVar10 = 1;
        sVar9 = 0x23;
      }
      goto _L0;
    }
  }
  else if (param_2 != 0xfff2) {
    if (0xfff2 < param_2) {
      if (param_2 == 0xfff3) {
        bVar10 = 1;
        sVar9 = 0x20;
        goto _L0;
      }
_L0:
      uVar4 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC5,uVar4,0x10000);
      return 0x102;
    }
    if (param_2 == 0xfff0) {
      if (param_3 == (undefined4 *)0x0) {
        uVar4 = 0x636;
_L404:
        zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c"
                  ,uVar4);
      }
      puVar5 = (undefined4 *)malloc(0x10);
      bVar10 = *(byte *)(param_3 + 2);
      pvVar6 = calloc((uint)bVar10,8);
      puVar7 = (undefined1 *)malloc(1);
      uVar1 = *(undefined1 *)param_3;
      *puVar5 = puVar7;
      *puVar7 = uVar1;
      puVar8 = (undefined4 *)malloc(4);
      uVar4 = param_3[1];
      puVar5[1] = puVar8;
      *(byte *)(puVar5 + 2) = bVar10;
      *puVar8 = uVar4;
      puVar5[3] = pvVar6;
    }
    else {
      if (param_2 != 0xfff1) goto _L0;
      uVar4 = 0x61f;
      if (param_3 == (undefined4 *)0x0) goto _L404;
      puVar5 = (undefined4 *)malloc(0x10);
      uVar2 = *(undefined2 *)param_3;
      *puVar5 = 0;
      *(undefined1 *)((int)puVar5 + 0xb) = 0;
      *(undefined2 *)(puVar5 + 1) = uVar2;
      *(undefined2 *)((int)puVar5 + 6) = uVar2;
      uVar2 = *(undefined2 *)((int)param_3 + 2);
      *(undefined1 *)(puVar5 + 3) = 0;
      *(undefined2 *)(puVar5 + 2) = uVar2;
      *(undefined1 *)((int)puVar5 + 10) = *(undefined1 *)(param_3 + 1);
    }
    bVar10 = 0x40;
    sVar9 = 0x10;
    param_3 = puVar5;
    goto _L0;
  }
  bVar10 = 1;
  sVar9 = 0x21;
_L0:
  if ((param_1 == (ushort *)0x0) || (*(int *)(param_1 + 6) == 0)) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar4,0x10000);
  }
  else {
    puVar13 = param_1;
    if (*(short *)(*(int *)(param_1 + 6) + 10) == 0x19) {
      do {
        puVar3 = *(ushort **)(puVar13 + 6);
        if (puVar3 == (ushort *)0x0) {
          __ptr = (undefined2 *)malloc(0x10);
          if (__ptr == (undefined2 *)0x0) {
            return 0x102;
          }
          if ((bVar10 & 0x40) == 0) {
_L0:
            __size = esp_zb_zcl_get_attribute_size(sVar9,param_3);
          }
          else {
            __size = sVar9;
            if ((param_3 == (undefined4 *)0x0) && (sVar9 != 0)) {
              zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c"
                        ,0x68);
              goto _L0;
            }
          }
          if (__size == 0xffff) {
_L0:
            free(__ptr);
            return 0x102;
          }
          pvVar6 = (void *)0x0;
          if (__size != 0) {
            pvVar6 = malloc(__size);
            if (pvVar6 == (void *)0x0) goto _L0;
            memcpy(pvVar6,param_3,__size);
          }
          iVar11 = *(int *)(param_1 + 6);
          *(byte *)((int)__ptr + 3) = bVar10;
          *(char *)(__ptr + 1) = (char)sVar9;
          uVar2 = *(undefined2 *)(iVar11 + 10);
          __ptr[3] = (short)pvVar6;
          *__ptr = (short)param_2;
          __ptr[4] = (short)((uint)pvVar6 >> 0x10);
          __ptr[2] = 0xffff;
          __ptr[5] = uVar2;
          *(undefined4 *)(__ptr + 6) = 0;
          *(undefined2 **)(puVar13 + 6) = __ptr;
          return 0;
        }
        puVar13 = puVar3;
      } while ((*puVar3 != param_2) || (puVar3[2] != 0xffff));
      uVar4 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC3,uVar4,0x10000,param_2);
    }
    else {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC2,uVar4,0x10000,*(undefined2 *)(*(int *)(param_1 + 6) + 10),0x19);
    }
  }
  return 0x102;
}

