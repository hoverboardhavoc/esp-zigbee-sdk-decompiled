/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr -> esp_zigbee_ota.o -> esp_zb_ota_upgrade_server_notify_req
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
  undefined4 uVar4;
  int iVar5;
  undefined4 *__ptr;
  void *pvVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  size_t __size;
  undefined4 *__ptr_00;
  int iVar9;
  
  iVar5 = get_ota_upgrade_server_variables(*param_1);
  if (iVar5 == 0) {
    return 0x102;
  }
  if ((uint)*(byte *)(iVar5 + 8) <= (uint)(byte)param_1[1]) {
    return 0x102;
  }
  iVar9 = *(int *)(param_1 + 0x24);
  if (iVar9 == 0) {
    return 0x102;
  }
  uVar2 = *(ushort *)(param_1 + 0x14);
  __ptr_00 = *(undefined4 **)((uint)(byte)param_1[1] * 8 + *(int *)(iVar5 + 0xc));
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
    uVar7 = *(undefined4 *)(param_1 + 0xc);
    *(short *)((int)__ptr + 0xe) = (short)uVar7;
    *(short *)(__ptr + 4) = (short)((uint)uVar7 >> 0x10);
    __ptr[0xd] = *(int *)(param_1 + 0x10) + __size;
    iVar5 = 0x38;
    if ((uVar2 & 1) != 0) {
      *(undefined1 *)(__ptr + 0xe) = param_1[0x16];
      iVar5 = 0x39;
    }
    puVar8 = (undefined1 *)((int)__ptr + iVar5);
    if ((uVar2 & 2) != 0) {
      pvVar6 = memcpy(puVar8,param_1 + 0x17,8);
      puVar8 = (undefined1 *)((int)pvVar6 + 8);
    }
    if ((*(ushort *)(__ptr + 2) & 4) != 0) {
      *puVar8 = param_1[0x20];
      puVar8[1] = param_1[0x21];
      puVar8[2] = param_1[0x22];
      puVar8[3] = param_1[0x23];
    }
  }
  s_ota_next_data_cb = iVar9;
  iVar5 = zb_zcl_get_ctx();
  *(code **)(iVar5 + 0xb8) = next_data_req_cb;
  iVar5 = zb_buf_get_out_func();
  if (iVar5 == 0) {
_L0:
    uVar4 = 0x102;
    if (__ptr != (undefined4 *)0x0) {
      free(__ptr);
      uVar7 = 0x102;
_L0:
      if (__ptr_00 == (undefined4 *)0x0) {
        return uVar7;
      }
      if (__ptr_00 == __ptr) {
        return uVar7;
      }
      goto _L0;
    }
  }
  else {
    puVar8 = (undefined1 *)zb_buf_get_tail_func(0x10);
    *puVar8 = *param_1;
    uVar1 = param_1[1];
    *(undefined4 **)(puVar8 + 4) = __ptr;
    puVar8[1] = uVar1;
    *(undefined4 *)(puVar8 + 0xc) = *(undefined4 *)(param_1 + 4);
    puVar8[8] = param_1[2];
    iVar5 = zb_zcl_ota_upgrade_insert_file(iVar5);
    if (iVar5 != 0) goto _L0;
    uVar7 = 0;
    uVar4 = 0;
    if (__ptr != (undefined4 *)0x0) goto _L0;
  }
  uVar7 = uVar4;
  if (__ptr_00 == (undefined4 *)0x0) {
    return uVar7;
  }
_L0:
  free(__ptr_00);
  return uVar7;
}

