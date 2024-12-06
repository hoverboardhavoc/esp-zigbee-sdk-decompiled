/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_ota.o -> esp_zb_ota_upgrade_server_notify_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ota_upgrade_server_notify_req(undefined1 *param_1)

{
  undefined1 uVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 *__ptr;
  void *pvVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  size_t __size;
  undefined4 uVar8;
  undefined4 *__ptr_00;
  int iVar9;
  
  iVar4 = get_ota_upgrade_server_variables(*param_1);
  if (iVar4 == 0) {
    return 0x102;
  }
  if ((uint)*(byte *)(iVar4 + 8) <= (uint)(byte)param_1[1]) {
    return 0x102;
  }
  iVar9 = *(int *)(param_1 + 0x24);
  if (iVar9 == 0) {
    return 0x102;
  }
  uVar2 = *(ushort *)(param_1 + 0x14);
  __ptr_00 = *(undefined4 **)((uint)(byte)param_1[1] * 8 + *(int *)(iVar4 + 0xc));
  __size = (uVar2 & 1) + 0x40;
  if ((uVar2 & 2) == 0) {
    __size = (uVar2 & 1) + 0x38;
  }
  if ((uVar2 & 4) != 0) {
    __size = __size + 4;
  }
  __ptr = (undefined4 *)malloc(__size);
  if (__ptr != (undefined4 *)0x0) {
    *__ptr = 0xbeef11e;
    *(undefined2 *)(__ptr + 1) = 0x100;
    *(undefined2 *)((int)__ptr + 0x12) = 2;
    memset(__ptr + 5,0,0x20);
    uVar3 = *(undefined2 *)(param_1 + 8);
    *(short *)((int)__ptr + 6) = (short)__size;
    *(ushort *)(__ptr + 2) = uVar2;
    *(undefined2 *)((int)__ptr + 10) = uVar3;
    *(undefined2 *)(__ptr + 3) = *(undefined2 *)(param_1 + 10);
    uVar6 = *(undefined4 *)(param_1 + 0xc);
    *(short *)((int)__ptr + 0xe) = (short)uVar6;
    *(short *)(__ptr + 4) = (short)((uint)uVar6 >> 0x10);
    __ptr[0xd] = *(int *)(param_1 + 0x10) + __size;
    iVar4 = 0x38;
    if ((uVar2 & 1) != 0) {
      *(undefined1 *)(__ptr + 0xe) = param_1[0x16];
      iVar4 = 0x39;
    }
    puVar7 = (undefined1 *)((int)__ptr + iVar4);
    if ((uVar2 & 2) != 0) {
      pvVar5 = memcpy(puVar7,param_1 + 0x17,8);
      puVar7 = (undefined1 *)((int)pvVar5 + 8);
    }
    if ((*(ushort *)(__ptr + 2) & 4) != 0) {
      *puVar7 = param_1[0x20];
      puVar7[1] = param_1[0x21];
      puVar7[2] = param_1[0x22];
      puVar7[3] = param_1[0x23];
    }
  }
  s_ota_next_data_cb = iVar9;
  iVar4 = zb_zcl_get_ctx();
  *(code **)(iVar4 + 0xb8) = next_data_req_cb;
  iVar4 = zb_buf_get_out_func();
  if (iVar4 == 0) {
_L0:
    uVar6 = 0x102;
    if (__ptr == (undefined4 *)0x0) {
_L0:
      uVar8 = uVar6;
      if (__ptr_00 == (undefined4 *)0x0) {
        return uVar8;
      }
      goto _L0;
    }
    free(__ptr);
    uVar8 = 0x102;
  }
  else {
    puVar7 = (undefined1 *)zb_buf_get_tail_func(0x10);
    *puVar7 = *param_1;
    uVar1 = param_1[1];
    *(undefined4 **)(puVar7 + 4) = __ptr;
    puVar7[1] = uVar1;
    *(undefined4 *)(puVar7 + 0xc) = *(undefined4 *)(param_1 + 4);
    puVar7[8] = param_1[2];
    iVar4 = zb_zcl_ota_upgrade_insert_file(iVar4);
    if (iVar4 != 0) goto _L0;
    uVar8 = 0;
    uVar6 = 0;
    if (__ptr == (undefined4 *)0x0) goto _L0;
  }
  if (__ptr_00 == (undefined4 *)0x0) {
    return uVar8;
  }
  if (__ptr_00 == __ptr) {
    return uVar8;
  }
_L0:
  free(__ptr_00);
  return uVar8;
}

