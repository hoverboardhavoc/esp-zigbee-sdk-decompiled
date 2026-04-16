/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> identify.o -> identify_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t identify_cluster_cli_cmd_proc_handler(void *arg)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uStack_3a;
  undefined1 auStack_38 [2];
  uint16_t timeout;
  zcl_packet_t rsp;
  
  iVar1 = 1;
  memset(auStack_38,0,0x28);
  if (arg != (void *)0x0) {
    iVar1 = 1;
    if (((*(byte *)((int)arg + 0x1a) & 8) != 0) &&
       (iVar1 = zcl_packet_init(auStack_38,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar1 == 0)) {
      if (*(char *)((int)arg + 0x20) == '\0') {
        uStack_3a = 0;
        uVar2 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),0,2,&uStack_3a);
        if (uVar2 == 0) {
          uVar2 = 0xffff;
        }
        uVar3 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        if (uVar3 < uVar2) {
          iVar1 = 0x80;
        }
        else {
          iVar1 = zcl_packet_setup_default_response(auStack_38,arg,0);
          if (iVar1 == 0) {
            zcl_packet_send(auStack_38,0);
            goto _L0;
          }
        }
      }
      else {
        iVar1 = 0x81;
      }
      zcl_packet_free(auStack_38);
    }
  }
_L0:
  return (ezb_zcl_status_t)iVar1;
}

