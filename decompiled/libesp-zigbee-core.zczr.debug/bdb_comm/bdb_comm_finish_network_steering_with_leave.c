/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_finish_network_steering_with_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_comm_finish_network_steering_with_leave(void)

{
  int iVar1;
  int iVar2;
  code *pcStack_18;
  undefined4 uStack_14;
  
  iVar1 = core_globals_get();
  if (*(char *)(iVar1 + 0xd4c) != '\x01') {
    iVar1 = core_globals_get();
    if (((*(char *)(iVar1 + 0xd4c) != '\0') && (iVar1 = nwk_is_joined_and_authed(), iVar1 != 0)) &&
       (iVar1 = zdo_create_mgmt_req(0x34), iVar1 != 0)) {
      iVar2 = zdo_mgmt_req_get_param();
      *(byte *)(iVar2 + 8) = *(byte *)(iVar2 + 8) | 2;
      iVar2 = zdo_mgmt_req_get_param(iVar1);
      *(byte *)(iVar2 + 8) = *(byte *)(iVar2 + 8) & 0xfe;
      uStack_14 = 0;
      pcStack_18 = bdb_comm_network_steering_handle_leave_done;
      zdo_mgmt_req_set_user_ctx(iVar1,&pcStack_18);
      iVar1 = zdo_send_mgmt_req(iVar1,0);
      if (iVar1 == 0) {
        return;
      }
      if (iVar1 == 0xc) {
        return;
      }
    }
    bdb_comm_finish_network_steering();
  }
  return;
}

