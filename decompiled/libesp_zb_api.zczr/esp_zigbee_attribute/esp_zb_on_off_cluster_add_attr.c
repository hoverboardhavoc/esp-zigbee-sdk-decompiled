/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_attribute.o -> esp_zb_on_off_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010256) */
/* WARNING: Removing unreachable block (ram,0x0001025c) */
/* WARNING: Removing unreachable block (ram,0x0001028a) */

undefined4 esp_zb_on_off_cluster_add_attr(ushort *param_1,uint param_2,void *param_3)

{
  undefined2 uVar1;
  ushort *puVar2;
  undefined2 *__ptr;
  size_t __size;
  void *__dest;
  undefined4 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  int iVar6;
  ushort *puVar7;
  
  if (param_2 < 0x4003) {
    if (param_2 < 0x4001) {
      if (param_2 == 0) {
        uVar5 = 0x15;
      }
      else {
        uVar5 = 1;
        if (param_2 != 0x4000) goto _L0;
      }
      uVar4 = 0x10;
    }
    else {
      uVar5 = 3;
      uVar4 = 0x21;
    }
  }
  else {
    if (param_2 != 0x4003) {
_L0:
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC5,uVar3,0x10000);
      return 0x102;
    }
    uVar5 = 3;
    uVar4 = 0x30;
  }
  if ((param_1 == (ushort *)0x0) || (*(int *)(param_1 + 6) == 0)) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar3,0x10000);
  }
  else {
    puVar7 = param_1;
    if (*(short *)(*(int *)(param_1 + 6) + 10) == 6) {
      do {
        puVar2 = *(ushort **)(puVar7 + 6);
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
          iVar6 = *(int *)(param_1 + 6);
          *(undefined1 *)((int)__ptr + 3) = uVar5;
          *(undefined1 *)(__ptr + 1) = uVar4;
          uVar1 = *(undefined2 *)(iVar6 + 10);
          __ptr[3] = (short)__dest;
          *__ptr = (short)param_2;
          __ptr[4] = (short)((uint)__dest >> 0x10);
          __ptr[2] = 0xffff;
          __ptr[5] = uVar1;
          *(undefined4 *)(__ptr + 6) = 0;
          *(undefined2 **)(puVar7 + 6) = __ptr;
          return 0;
        }
        puVar7 = puVar2;
      } while ((*puVar2 != param_2) || (puVar2[2] != 0xffff));
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC3,uVar3,0x10000,param_2);
    }
    else {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC2,uVar3,0x10000,*(undefined2 *)(*(int *)(param_1 + 6) + 10),6);
    }
  }
  return 0x102;
}

