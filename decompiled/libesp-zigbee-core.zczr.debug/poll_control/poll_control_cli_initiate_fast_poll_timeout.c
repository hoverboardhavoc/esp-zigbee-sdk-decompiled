/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_cli_initiate_fast_poll_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void poll_control_cli_initiate_fast_poll_timeout(zcl_packet_t *req,uint32_t delay_ms)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  ezb_grpaddr_t eVar4;
  undefined2 *extraout_a1;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  if (req == (zcl_packet_t *)0x0) {
    uVar5 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/poll_control.c"
                          ,0x20a,"poll_control_cli_initiate_fast_poll_timeout",&_LC8);
    uStack_40 = 0;
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    iVar3 = zcl_packet_to_message(&uStack_40,uVar5);
    if (iVar3 == 0) {
      uStack_34 = CONCAT31(uStack_34._1_3_,0xfe);
      uStack_38 = uVar5;
      zcl_core_action_schedule(0x3d,&uStack_40);
      if (((uStack_34 & 0xff) == 0xfe) || ((uStack_34 & 0xff) == 0)) {
        *extraout_a1 = uStack_34._2_2_;
      }
    }
    return;
  }
  puVar1 = (undefined4 *)calloc(1,0x28);
  pvVar2 = calloc(1,0x10);
  uVar10 = *(undefined4 *)((int)&(req->header).src_addr.u + 2);
  uVar9 = *(undefined4 *)((int)&(req->header).src_addr.u + 6);
  eVar4 = (req->header).dst_addr.u.group_addr;
  uVar5 = *(undefined4 *)((int)&(req->header).dst_addr.u + 4);
  uVar6 = *(undefined4 *)&(req->header).src_ep;
  uVar7 = *(undefined4 *)&(req->header).profile_id;
  uVar8 = *(undefined4 *)&(req->header).manuf_code;
  *puVar1 = *(undefined4 *)&(req->header).src_addr;
  puVar1[1] = uVar10;
  puVar1[2] = uVar9;
  *(ezb_grpaddr_t *)(puVar1 + 3) = eVar4;
  puVar1[4] = uVar5;
  puVar1[5] = uVar6;
  puVar1[6] = uVar7;
  puVar1[7] = uVar8;
  *(undefined2 *)(puVar1 + 8) = *(undefined2 *)&(req->header).cmd_id;
  puVar1[9] = pvVar2;
  milli_timer_init(poll_control_cli_stop_fast_poll,puVar1);
  milli_timer_start(pvVar2,delay_ms);
  return;
}

