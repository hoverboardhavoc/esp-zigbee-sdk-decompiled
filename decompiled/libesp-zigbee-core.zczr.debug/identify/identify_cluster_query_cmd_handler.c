/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> identify.o -> identify_cluster_query_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void identify_cluster_query_cmd_handler(int param_1,int param_2)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined2 uStack_12;
  
  uVar1 = *(undefined1 *)(param_1 + 0x15);
  if (param_2 == 0) {
    cVar2 = -2;
    goto _L0;
  }
  iVar3 = ezb_zcl_is_identifying(uVar1);
  if (iVar3 == 0) {
    cVar2 = '\0';
  }
  else {
    iVar3 = identify_srv_get_attr_desc(uVar1,0);
    if (iVar3 == 0) {
      cVar2 = -0x7a;
      goto _L0;
    }
    if (*(undefined2 **)(iVar3 + 8) == (undefined2 *)0x0) {
      cVar2 = -0x7a;
      goto _L0;
    }
    uStack_12 = **(undefined2 **)(iVar3 + 8);
    cVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_12);
    if (cVar2 != '\0') goto _L0;
  }
  iVar3 = zmsg_get_length(*(undefined4 *)(param_2 + 0x24));
  if (iVar3 != 0) {
    zcl_packet_setup_response(param_2,param_1,0);
    return;
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,cVar2);
  return;
}

