/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> on_off_cluster_off_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t on_off_cluster_off_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  int iVar2;
  int extraout_a1;
  
  if ((packet != (zcl_packet_t *)0x0) && (rsp != (zcl_packet_t *)0x0)) {
    on_off_process_transition((packet->header).dst_ep,(packet->header).cmd_id,'\0',0,0);
    eVar1 = zcl_packet_setup_default_response(rsp,packet,0);
    return eVar1;
  }
  iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x156,
                        "on_off_cluster_off_cmd_handler","packet && rsp");
  if ((iVar2 != 0) && (extraout_a1 != 0)) {
    on_off_process_transition(*(uint8_t *)(iVar2 + 0x15),*(uint8_t *)(iVar2 + 0x20),'\x01',0,0);
    eVar1 = zcl_packet_setup_default_response(extraout_a1,iVar2,0);
    return eVar1;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x165,
                "on_off_cluster_on_cmd_handler","packet && rsp");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

