/*
 * Last changed at upstream commit 2941fbcc815001461b9ea708a1d755b07ce24ea3
 * https://github.com/espressif/esp-zigbee-sdk/commit/2941fbcc815001461b9ea708a1d755b07ce24ea3
 * Upstream date: 2022-08-09 20:36:03 +0800
 * Upstream subject: esp-zigbee-sdk: First sdk release
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_core.o -> zcl_endpoint_handler_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char zcl_endpoint_handler_callback(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined2 *puVar5;
  
  iVar2 = zb_buf_get_tail_func(0x1a);
  if (*(char *)(iVar2 + 0x13) == '\x01') {
    uVar4 = (uint)*(ushort *)(iVar2 + 0xe);
    if (uVar4 < 9) {
      if ((0x179U >> (uVar4 & 0x1f) & 1) == 0) {
        return '\0';
      }
    }
    else if (uVar4 != 0x300) {
      return '\0';
    }
    cVar1 = *(char *)(iVar2 + 0x15);
    if (cVar1 != '\0') {
      if (*(char *)(iVar2 + 0x12) == '\x01') {
        if (zcl_read_attr_user_cb == (code *)0x0) {
          cVar1 = '\0';
        }
        else {
          uVar4 = zb_buf_len_func(param_1);
          if (uVar4 < 3) {
            puVar5 = (undefined2 *)0x0;
          }
          else {
            puVar5 = (undefined2 *)zb_buf_begin_func(param_1);
            if (puVar5 != (undefined2 *)0x0) {
              if (*(char *)(puVar5 + 1) == '\0') {
                iVar2 = zb_zcl_get_attribute_size(*(undefined1 *)((int)puVar5 + 3),puVar5 + 2);
                uVar4 = iVar2 + 4U & 0xff;
                zb_buf_len_func(param_1);
              }
              else {
                uVar4 = 3;
              }
              uVar3 = zb_buf_len_func(param_1);
              if (uVar3 < uVar4) {
                return '\0';
              }
              zb_buf_cut_left_func(param_1,uVar4);
            }
          }
          if (puVar5 == (undefined2 *)0x0) {
            cVar1 = '\0';
          }
          else {
            (*zcl_read_attr_user_cb)
                      (*(undefined1 *)(puVar5 + 1),*puVar5,*(undefined1 *)((int)puVar5 + 3),
                       puVar5 + 2,zcl_read_attr_user_cb);
            zb_buf_free_func(param_1);
          }
        }
      }
      else {
        cVar1 = '\0';
      }
    }
  }
  else {
    cVar1 = '\0';
  }
  return cVar1;
}

