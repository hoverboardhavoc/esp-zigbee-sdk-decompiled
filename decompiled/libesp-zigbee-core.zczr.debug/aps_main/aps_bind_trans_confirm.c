/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_bind_trans_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_bind_trans_confirm(zmsg_t *bt_msg,ezb_err_t error)

{
  uint uVar1;
  aps_bind_src_t *paStack_24;
  aps_bind_ctx_t bind;
  aps_bind_trans_ctx_t bind_trans;
  
  bind.cnt = '\0';
  bind._13_3_ = 0;
  zmsg_get_footer(&bind.cnt,4);
  zmsg_free(bt_msg);
  if ((*(ushort *)(bind._12_4_ + 0x16) & 0x20) == 0) {
    paStack_24 = (aps_bind_src_t *)0x0;
    bind.src = (aps_bind_src_t *)0x0;
    bind.dst = (aps_bind_dst_t *)0x0;
    bind.error = 0;
    zmsg_get_footer(&paStack_24,0x10);
    if ((bind.error & 0xffU) != 0) {
      uVar1 = (bind.error & 0xffU) - 1;
      bind.error = CONCAT31(bind.error._1_3_,(char)uVar1);
      if (error != 0) {
        bind.dst = (aps_bind_dst_t *)error;
      }
      if ((((uVar1 & 0xff) == 0) && (bind.src != (aps_bind_src_t *)0x0)) &&
         (error = aps_bind_trans_schedule_next_nmsg
                            (paStack_24,(aps_bind_dst_t *)bind.src,(zmsg_t *)bind._12_4_,
                             (uint8_t *)&bind.error),
         (aps_bind_dst_t *)error != (aps_bind_dst_t *)0x0)) {
        bind.dst = (aps_bind_dst_t *)error;
      }
      if ((bind.error & 0xffU) != 0) {
        zmsg_update_footer(bind._12_4_,&paStack_24,0x10);
        return;
      }
      goto _L0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_main.c",0x163,
                  "aps_bind_trans_confirm",
                  "!zmsg_test_flag(bind_trans.orig_msg, ((1 << ((5) % (sizeof(unsigned long) * 8)))))"
                 );
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_main.c",0x168,
                "aps_bind_trans_confirm","bind.cnt > 0");
_L0:
  zmsg_remove_footer(bind._12_4_,0x10);
  aps_send_confirm((zmsg_t *)bind._12_4_,error);
  return;
}

