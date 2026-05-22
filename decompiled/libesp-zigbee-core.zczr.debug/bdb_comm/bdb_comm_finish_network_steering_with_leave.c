/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_comm.o -> bdb_comm_finish_network_steering_with_leave
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bdb_comm_finish_network_steering_with_leave(void)

{
  zdo_mgmt_req_handle_t leave_handle;
  _Bool _Var1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  code *pcStack_18;
  undefined4 uStack_14;
  
  iVar2 = core_globals_get();
  if (*(char *)(iVar2 + 0xd4c) != '\x01') {
    iVar2 = core_globals_get();
    if (((*(char *)(iVar2 + 0xd4c) != '\0') &&
        (_Var1 = nwk_is_joined_and_authed(), CONCAT31(extraout_var,_Var1) != 0)) &&
       (iVar2 = zdo_create_mgmt_req(0x34), iVar2 != 0)) {
      iVar3 = zdo_mgmt_req_get_param();
      *(byte *)(iVar3 + 8) = *(byte *)(iVar3 + 8) | 2;
      iVar3 = zdo_mgmt_req_get_param(iVar2);
      *(byte *)(iVar3 + 8) = *(byte *)(iVar3 + 8) & 0xfe;
      uStack_14 = 0;
      pcStack_18 = bdb_comm_network_steering_handle_leave_done;
      zdo_mgmt_req_set_user_ctx(iVar2,&pcStack_18);
      iVar2 = zdo_send_mgmt_req(iVar2,0);
      if (iVar2 == 0) {
        return;
      }
      if (iVar2 == 0xc) {
        return;
      }
    }
    bdb_comm_finish_network_steering();
  }
  return;
}

