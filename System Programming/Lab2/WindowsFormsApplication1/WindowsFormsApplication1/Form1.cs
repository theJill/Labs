using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        static double k;
        public Form1()
        {
            InitializeComponent();
            textBox1.Text = " ";
        }

        private void button1_Click( object sender, EventArgs e )
        {
            k = Convert.ToUInt16(textBox1.Text);
            MessageBox.Show( axMFCActiveXControl11.TestMyMethod(k).ToString() );//вызов метода из activex
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

    }
}
