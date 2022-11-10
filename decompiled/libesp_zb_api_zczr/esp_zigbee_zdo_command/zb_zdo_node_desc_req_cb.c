/*
 * Last changed at upstream commit 6f86421a4970072ce8039b9d5be911c385f38303
 * https://github.com/espressif/esp-zigbee-sdk/commit/6f86421a4970072ce8039b9d5be911c385f38303
 * Upstream date: 2022-11-10 11:13:02 +0800
 * Upstream subject: examples: apply new signal handler API function
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> zb_zdo_node_desc_req_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zdo_node_desc_req_cb(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  void *__ptr;
  byte *pbVar3;
  int iVar4;
  
  uVar2 = ZDO_INVALID_SHORT_ADDR;
  __ptr = malloc(0xd);
  pbVar3 = (byte *)zb_buf_begin_func(param_1);
  bVar1 = *pbVar3;
  iVar4 = zb_buf_begin_func(param_1);
  if (*(char *)(iVar4 + 1) == '\0') {
    uVar2 = *(undefined2 *)(iVar4 + 2);
    __ptr = (void *)(iVar4 + 4);
  }
  if (*(code **)(node_desc_user_cb + (uint)bVar1 * 4) != (code *)0x0) {
    (**(code **)(node_desc_user_cb + (uint)bVar1 * 4))(uVar2,__ptr);
    *(undefined4 *)(node_desc_user_cb + (uint)bVar1 * 4) = 0;
  }
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  free(__ptr);
  return;
}

