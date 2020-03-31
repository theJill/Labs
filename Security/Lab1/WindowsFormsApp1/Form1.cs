using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            List<int> list = new List<int>();
            if (textBox1.Text != "")
            {
                int a = Convert.ToInt32(textBox1.Text);
                list.Add(a);
            }
            if (textBox2.Text != "")
            {
                int b = Convert.ToInt32(textBox2.Text);
                list.Add(b);
            }
            if (textBox3.Text != "")
            {
                int c = Convert.ToInt32(textBox3.Text);
                list.Add(c);
            }
            if (textBox4.Text != "")
            {
                int d = Convert.ToInt32(textBox4.Text);
                list.Add(d);
            }
            if (textBox5.Text != "")
            {
                int ee = Convert.ToInt32(textBox5.Text);
                list.Add(ee);
            }
            if (textBox6.Text != "")
            {
                int f = Convert.ToInt32(textBox6.Text);
                list.Add(f);
            }

            int[] arr = list.ToArray();
            int n = arr.Length;

            richTextBox1.Text = Convert.ToString(GCD.findGCD(arr, n));
        }
        private void button2_Click(object sender, EventArgs e)
        {
            int startnumber = Convert.ToInt32(textBox7.Text);
            int endnumber = Convert.ToInt32(textBox8.Text);
            List<string> primes = WindowsFormsApp1.PrimeNumber.allPrimeInRange(startnumber, endnumber);
            string outputs = "";
            foreach (string prime in primes)
            {
                outputs = outputs + prime + " ";
            }
            richTextBox2.Text = outputs;
        }
    }
}
