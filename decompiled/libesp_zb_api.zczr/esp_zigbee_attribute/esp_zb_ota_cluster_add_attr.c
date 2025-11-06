/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_attribute.o -> esp_zb_ota_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010268) */

undefined4 esp_zb_ota_cluster_add_attr(ushort *param_1,uint param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  ushort *puVar3;
  ushort *puVar4;
  undefined2 *__ptr;
  size_t __size;
  undefined4 uVar5;
  undefined4 *puVar6;
  void *pvVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  size_t sVar10;
  byte bVar11;
  int iVar12;
  uint uVar13;
  
  if (param_2 < 0xd) {
    bVar11 = 1;
    if (param_2 == 0) {
      sVar10 = 0xf0;
      goto _L0;
    }
    uVar13 = 1 << (param_2 & 0x1f);
    if ((uVar13 & 0x3a8) == 0) {
      if ((uVar13 & 0x416) == 0) {
        if ((uVar13 >> 6 & 0x61) == 0) goto _L0;
        sVar10 = 0x30;
      }
      else {
        sVar10 = 0x23;
      }
      goto _L0;
    }
  }
  else if (param_2 != 0xfff2) {
    if (0xfff2 < param_2) {
      if (param_2 == 0xfff3) {
        bVar11 = 1;
        sVar10 = 0x20;
        goto _L0;
      }
_L0:
      uVar5 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: incorrect/unsupported attribute_id!\n",uVar5,0x10000);
      return 0x102;
    }
    if (param_2 == 0xfff0) {
      if (param_3 == (undefined4 *)0x0) {
        uVar5 = 0x636;
_L403:
        zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c"
                  ,uVar5);
      }
      puVar6 = (undefined4 *)malloc(0x10);
      bVar11 = *(byte *)(param_3 + 2);
      pvVar7 = calloc((uint)bVar11,8);
      puVar8 = (undefined1 *)malloc(1);
      uVar1 = *(undefined1 *)param_3;
      *puVar6 = puVar8;
      *puVar8 = uVar1;
      puVar9 = (undefined4 *)malloc(4);
      uVar5 = param_3[1];
      puVar6[1] = puVar9;
      *(byte *)(puVar6 + 2) = bVar11;
      *puVar9 = uVar5;
      puVar6[3] = pvVar7;
    }
    else {
      if (param_2 != 0xfff1) goto _L0;
      uVar5 = 0x61f;
      if (param_3 == (undefined4 *)0x0) goto _L403;
      puVar6 = (undefined4 *)malloc(0x10);
      uVar2 = *(undefined2 *)param_3;
      *puVar6 = 0;
      *(undefined1 *)((int)puVar6 + 0xb) = 0;
      *(undefined2 *)(puVar6 + 1) = uVar2;
      *(undefined2 *)((int)puVar6 + 6) = uVar2;
      uVar2 = *(undefined2 *)((int)param_3 + 2);
      *(undefined1 *)(puVar6 + 3) = 0;
      *(undefined2 *)(puVar6 + 2) = uVar2;
      *(undefined1 *)((int)puVar6 + 10) = *(undefined1 *)(param_3 + 1);
    }
    bVar11 = 0x40;
    sVar10 = 0x10;
    param_3 = puVar6;
    goto _L0;
  }
  bVar11 = 1;
  sVar10 = 0x21;
_L0:
  if ((param_1 == (ushort *)0x0) || (*(int *)(param_1 + 6) == 0)) {
    uVar5 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: Uninitialized attribute linked list!\n",uVar5,0x10000);
  }
  else {
    puVar3 = param_1;
    if (*(short *)(*(int *)(param_1 + 6) + 10) == 0x19) {
      do {
        puVar4 = *(ushort **)(puVar3 + 6);
        if (puVar4 == (ushort *)0x0) {
          __ptr = (undefined2 *)malloc(0x10);
          if (__ptr == (undefined2 *)0x0) {
            return 0x102;
          }
          if ((bVar11 & 0x40) == 0) {
_L0:
            __size = esp_zb_zcl_get_attribute_size(sVar10,param_3);
          }
          else {
            __size = sVar10;
            if ((param_3 == (undefined4 *)0x0) && (sVar10 != 0)) {
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
          pvVar7 = (void *)0x0;
          if (__size != 0) {
            pvVar7 = malloc(__size);
            if (pvVar7 == (void *)0x0) goto _L0;
            memcpy(pvVar7,param_3,__size);
          }
          iVar12 = *(int *)(param_1 + 6);
          *(byte *)((int)__ptr + 3) = bVar11;
          *(char *)(__ptr + 1) = (char)sVar10;
          uVar2 = *(undefined2 *)(iVar12 + 10);
          __ptr[3] = (short)pvVar7;
          *__ptr = (short)param_2;
          __ptr[4] = (short)((uint)pvVar7 >> 0x10);
          __ptr[2] = 0xffff;
          __ptr[5] = uVar2;
          *(undefined4 *)(__ptr + 6) = 0;
          *(undefined2 **)(puVar3 + 6) = __ptr;
          return 0;
        }
        puVar3 = puVar4;
      } while ((*puVar4 != param_2) || (puVar4[2] != 0xffff));
      uVar5 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: The requested add attribute ID:0x%x is already existed\n",uVar5
              ,0x10000,param_2);
    }
    else {
      uVar5 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: Wrong cluster(0x%04x) to add attribute, expect 0x%04x\n",uVar5,
              0x10000,*(undefined2 *)(*(int *)(param_1 + 6) + 10),0x19);
    }
  }
  return 0x102;
}

