/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_endpoint_handler_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char zcl_endpoint_handler_callback(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  undefined1 auStack_3c [16];
  undefined4 uStack_2c;
  
  iVar3 = zb_buf_get_tail_func(0x1a);
  if (*(char *)(iVar3 + 0x13) != '\x01') {
    return '\0';
  }
  uVar2 = (uint)*(ushort *)(iVar3 + 0xe);
  if (uVar2 < 9) {
    if ((0x179U >> (uVar2 & 0x1f) & 1) == 0) {
_L0:
      uVar4 = esp_zb_get_global_custom_cluster_id();
      if (uVar2 != uVar4) {
        return '\0';
      }
      if (zcl_custom_cluster_cmd_cb != (code *)0x0) {
        esp_zb_custom_cluster_get_cmd_req(param_1,auStack_3c,0);
        (*zcl_custom_cluster_cmd_cb)(uRam00000000,uStack_2c,zcl_custom_cluster_cmd_cb);
        return '\0';
      }
      return '\0';
    }
  }
  else if (uVar2 != 0x300) goto _L0;
  cVar1 = *(char *)(iVar3 + 0x15);
  if (cVar1 != '\0') {
    if (*(char *)(iVar3 + 0x12) == '\x01') {
      if (zcl_read_attr_user_cb == (code *)0x0) {
        cVar1 = '\0';
      }
      else {
        uVar2 = zb_buf_len_func(param_1);
        if (uVar2 < 3) {
          puVar5 = (undefined2 *)0x0;
        }
        else {
          puVar5 = (undefined2 *)zb_buf_begin_func(param_1);
          if (puVar5 != (undefined2 *)0x0) {
            if (*(char *)(puVar5 + 1) == '\0') {
              iVar3 = zb_zcl_get_attribute_size(*(undefined1 *)((int)puVar5 + 3),puVar5 + 2);
              uVar2 = iVar3 + 4U & 0xff;
              zb_buf_len_func(param_1);
            }
            else {
              uVar2 = 3;
            }
            uVar4 = zb_buf_len_func(param_1);
            if (uVar4 < uVar2) {
              return '\0';
            }
            zb_buf_cut_left_func(param_1,uVar2);
          }
        }
        if (puVar5 == (undefined2 *)0x0) {
          cVar1 = '\0';
        }
        else {
          (*zcl_read_attr_user_cb)
                    (*(undefined1 *)(puVar5 + 1),*puVar5,*(undefined1 *)((int)puVar5 + 3),puVar5 + 2
                     ,zcl_read_attr_user_cb);
          zb_buf_free_func(param_1);
        }
      }
    }
    else {
      cVar1 = '\0';
    }
  }
  return cVar1;
}

